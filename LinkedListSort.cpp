#include "LinkedListSort.h"
#include <iostream>
using namespace std;

// Modified insertion sort for linked list
void insertion_sort(Node*& head) {
    if (!head) return;

    Node* current = head->next;  // Start from second node (j = 1)
    Node* prev = head;

    bool insertionNeeded = false;

    while (current) {  // for (j = 1; j < num.size(); j++)
        int key = current->data;  // key = num[j]
        insertionNeeded = false;

        Node* i = head;
        Node* iPrev = nullptr;

        // Find position to insert (i = j - 1; i >= 0; i--)
        while (i != current) {
            if (key < i->data) {  // if (key < num[i])
                // Remove current from its position
                prev->next = current->next;

                // Insert current before i
                if (iPrev == nullptr) {
                    // Insert at beginning
                    current->next = head;
                    head = current;
                }
                else {
                    // Insert in middle
                    iPrev->next = current;
                    current->next = i;
                }

                insertionNeeded = true;
                break;
            }
            iPrev = i;
            i = i->next;
        }

        if (insertionNeeded) {
            // Key was inserted into proper location
            current = prev->next;  // Move to next node
        }
        else {
            // No insertion needed, move forward
            prev = current;
            current = current->next;
        }
    }
}

// Insert element at end of list
void insert(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Display the linked list
void display(Node* head) {
    if (!head) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Clear all nodes
void clear(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Main function to test the insertion sort
int main() {
    Node* head = nullptr;

    // Insert test values: 20, 65, 30, 10
    insert(head, 20);
    insert(head, 65);
    insert(head, 30);
    insert(head, 10);

    cout << "Before sorting: ";
    display(head);

    insertion_sort(head);

    cout << "After sorting: ";
    display(head);

    clear(head);
    return 0;
}