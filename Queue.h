#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

// Forward declaration of the Queue class
template <typename T>
class Queue;

// Queue class declaration
template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value);
    };

    Node* frontNode;
    Node* backNode;
    int count;

public:
    // Constructor and Destructor
    Queue();
    ~Queue();

    // Core Queue operations
    void push(const T& value);
    void pop();
    T& front();
    bool empty() const;
    int size() const;

    // Advanced operations
    void move_to_rear();
    void display();
};

// Include implementation file for template class
