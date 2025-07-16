#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Queue {
private:
    T* arr;           // Array to store queue elements
    int frontIndex;   // Index of front element
    int rearIndex;    // Index of rear element
    int capacity;     // Maximum capacity of queue
    int count;        // Current number of elements

public:
    // Constructor - Initialize empty queue
    Queue(int size = 100) {
        capacity = size;
        arr = new T[capacity];
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    // Destructor - Free allocated memory
    ~Queue() {
        delete[] arr;
    }

    // Push operation - Add element to rear of queue
    void push(const T& item) {
        // Check if queue is full
        if (count == capacity) {
            throw std::overflow_error("Queue is full");
        }

        // Calculate next rear position (circular)
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = item;
        count++;
    }

    // Pop operation - Remove element from front of queue
    void pop() {
        // Check if queue is empty
        if (empty()) {
            throw std::underflow_error("Queue is empty");
        }

        // Move front index forward (circular)
        frontIndex = (frontIndex + 1) % capacity;
        count--;
    }

    // Front operation - Get front element without removing it
    T front() const {
        // Check if queue is empty
        if (empty()) {
            throw std::underflow_error("Queue is empty");
        }

        return arr[frontIndex];
    }

    // Size operation - Return current number of elements
    int size() const {
        return count;
    }

    // Empty operation - Check if queue is empty
    bool empty() const {
        return count == 0;
    }

    // Move to rear operation - Move front element to rear using push, front, and pop
    void move_to_rear() {
        // Check if queue has elements to move
        if (empty()) {
            throw std::underflow_error("Queue is empty - cannot move element");
        }

        // If only one element, no need to move
        if (size() == 1) {
            return;
        }

        // Get front element, remove it, and add to rear
        T frontElement = front();  // Get front element
        pop();                     // Remove front element
        push(frontElement);        // Add it to rear
    }
};

#endif