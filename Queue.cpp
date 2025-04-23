#include "Queue.h"
// Node constructor implementation
template <typename T>
Queue<T>::Node::Node(const T& value) : data(value), next(nullptr) {}

// Queue constructor implementation
template <typename T>
Queue<T>::Queue() : frontNode(nullptr), backNode(nullptr), count(0) {}

// Queue destructor implementation
template <typename T>
Queue<T>::~Queue() {
    while (!empty()) {
        pop();
    }
}

// Add element to the back of the queue
template <typename T>
void Queue<T>::push(const T& value) {
    Node* newNode = new Node(value);

    if (empty()) {
        frontNode = newNode;
    }
    else {
        backNode->next = newNode;
    }

    backNode = newNode;
    count++;
}

// Remove the front element
template <typename T>
void Queue<T>::pop() {
    if (empty()) {
        throw runtime_error("Cannot pop from an empty queue");
    }

    Node* temp = frontNode;
    frontNode = frontNode->next;
    delete temp;
    count--;

    if (count == 0) {
        backNode = nullptr;
    }
}

// Get the front element
template <typename T>
T& Queue<T>::front() {
    if (empty()) {
        throw runtime_error("Queue is empty");
    }
    return frontNode->data;
}

// Check if queue is empty
template <typename T>
bool Queue<T>::empty() const {
    return count == 0;
}

// Get the size of the queue
template <typename T>
int Queue<T>::size() const {
    return count;
}

// Move the front element to the rear
template <typename T>
void Queue<T>::move_to_rear() {
    if (empty() || size() == 1) {
        // If queue is empty or has only one element, no change needed
        return;
    }

    // Store the front element
    T frontValue = front();

    // Remove it from the front
    pop();

    // Add it to the rear
    push(frontValue);
}

// Display all elements in the queue using only basic queue operations
template <typename T>
void Queue<T>::display() {
    if (empty()) {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << "Queue elements: ";

    // Create a temporary queue to store elements as we process them
    Queue<T> tempQueue;

    // Empty the original queue, display each element, and store in temp queue
    while (!empty()) {
        T value = front();
        cout << value << " ";
        pop();
        tempQueue.push(value);
    }

    cout << endl;

    // Restore the original queue
    while (!tempQueue.empty()) {
        push(tempQueue.front());
        tempQueue.pop();
    }
}