#ifndef LINKEDLISTSORT_H
#define LINKEDLISTSORT_H

// Node structure for linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function declarations
void insertionSort(Node*& head);
void insert(Node*& head, int value);
void display(Node* head);
void clear(Node*& head);

#endif