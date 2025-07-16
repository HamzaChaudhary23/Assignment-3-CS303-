#include "Queue.h"
#include <iostream>

int main() {
    try {
        // ==================== OPERATION A ====================
        // Instantiate the queue with integers and push 10 values into the queue
        std::cout << "=== OPERATION A: Creating queue and pushing 10 values ===" << std::endl;

        Queue<int> intQueue(20);  // Create queue with capacity 20

        // Push 10 values into the queue (1, 2, 3, ..., 10)
        for (int i = 1; i <= 10; i++) {
            intQueue.push(i);
            std::cout << "Pushed: " << i << std::endl;
        }

        std::cout << "Queue size after pushing: " << intQueue.size() << std::endl;
        std::cout << "Is queue empty? " << (intQueue.empty() ? "Yes" : "No") << std::endl;
        std::cout << std::endl;

        // ==================== OPERATION B ====================
        // Display all the elements in a queue using just the queue functions
        std::cout << "=== OPERATION B: Displaying queue elements using only queue functions ===" << std::endl;

        // Create temporary queue to preserve original
        Queue<int> tempQueue(20);
        std::cout << "Queue elements (front to rear): ";

        // Transfer elements to temp queue while displaying
        while (!intQueue.empty()) {
            int element = intQueue.front();  // Get front element
            std::cout << element << " ";     // Display it
            tempQueue.push(element);         // Save to temp queue
            intQueue.pop();                  // Remove from original
        }
        std::cout << std::endl;

        // Restore original queue
        while (!tempQueue.empty()) {
            intQueue.push(tempQueue.front());
            tempQueue.pop();
        }

        std::cout << "Queue restored. Size: " << intQueue.size() << std::endl;
        std::cout << "Front element: " << intQueue.front() << std::endl;
        std::cout << std::endl;

        // ==================== OPERATION C ====================
        // Write a new queue function called move_to_rear
        std::cout << "=== OPERATION C: Move to rear functionality ===" << std::endl;

        std::cout << "Before move_to_rear:" << std::endl;
        std::cout << "Front element: " << intQueue.front() << std::endl;
        std::cout << "Queue size: " << intQueue.size() << std::endl;

        // Display current queue state
        Queue<int> displayQueue(20);
        std::cout << "Current queue: ";
        while (!intQueue.empty()) {
            int element = intQueue.front();
            std::cout << element << " ";
            displayQueue.push(element);
            intQueue.pop();
        }
        std::cout << std::endl;

        // Restore queue
        while (!displayQueue.empty()) {
            intQueue.push(displayQueue.front());
            displayQueue.pop();
        }

        // Perform move_to_rear operation
        intQueue.move_to_rear();

        std::cout << "\nAfter move_to_rear:" << std::endl;
        std::cout << "New front element: " << intQueue.front() << std::endl;
        std::cout << "Queue size: " << intQueue.size() << std::endl;

        // Display queue after move_to_rear
        std::cout << "Queue after move_to_rear: ";
        while (!intQueue.empty()) {
            int element = intQueue.front();
            std::cout << element << " ";
            displayQueue.push(element);
            intQueue.pop();
        }
        std::cout << std::endl;

        // Restore queue one more time
        while (!displayQueue.empty()) {
            intQueue.push(displayQueue.front());
            displayQueue.pop();
        }

        // Demonstrate multiple move_to_rear operations
        std::cout << "\nDemonstrating multiple move_to_rear operations:" << std::endl;
        for (int i = 0; i < 3; i++) {
            std::cout << "Move " << (i + 1) << " - Front element: " << intQueue.front();
            intQueue.move_to_rear();
            std::cout << " -> New front: " << intQueue.front() << std::endl;
        }

        std::cout << "\nFinal queue size: " << intQueue.size() << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}