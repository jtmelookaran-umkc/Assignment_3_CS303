#include <iostream>
#include <vector>
#include "Queue.h"
#include "Recursive_Search.cpp"
#include "Insertion.h"

using namespace std;

void Queue_Func() {
    cout << "===== QUEUE DEMONSTRATION =====" << endl;

    Queue<int> intQueue;
    //instantiate with 10 values 
    cout << "Pushing 10 values into the queue:" << endl;
    for (int i = 1; i <= 10; i++) {
        intQueue.push(i * 10);
        cout << "Pushed: " << i * 10 << endl;
    }

    cout << "\nInitial queue:" << endl;
    intQueue.display();
    //Show functionality with size and front
    cout << "\nQueue size: " << intQueue.size() << endl;
    cout << "Front element: " << intQueue.front() << endl;
    //Added move to rear func
    cout << "\nAfter move_to_rear():" << endl;
    intQueue.move_to_rear();
    intQueue.display();
    //pop functionality with multiple elements
    cout << "\nRemoving five elements from the queue:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Popped: " << intQueue.front() << endl;
        intQueue.pop();
    }

    cout << "\nRemaining queue:" << endl;
    intQueue.display();

    cout << "\nRotating remaining elements:" << endl;
    for (int i = 0; i < 5; i++) {
        intQueue.move_to_rear();
        cout << "After move " << (i + 1) << ": ";
        intQueue.display();
    }

    //Added insertion sort functionality 
    cout << "\nSorting the queue using insertion sort:" << endl;
    insertionSortQueue(intQueue);
    intQueue.display();

}

void Recursive_Func() {
    cout << "\n===== RECURSIVE SEARCH DEMONSTRATION =====" << endl;
    //initial vector of values 
    vector<int> numbers = { 10, 20, 30, 10, 40, 50, 10, 60, 10, 70 };
    //iterate through the vector 
    cout << "Vector contents: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    //initalize the values we are searching for
    int target1 = 10;
    int target2 = 40;
    int target3 = 80;
    //create variables for result
    int result1 = findLastOccurrence(numbers, target1);
    int result2 = findLastOccurrence(numbers, target2);
    int result3 = findLastOccurrence(numbers, target3);
    //output stream 
    cout << "Last occurrence of " << target1 << ": " << result1 << endl;
    cout << "Last occurrence of " << target2 << ": " << result2 << endl;
    cout << "Last occurrence of " << target3 << ": " << result3 << endl;

    cout << "\nVerification:" << endl;
    cout << "Index " << result1 << " contains: " << (result1 != -1 ? to_string(numbers[result1]) : "not found") << endl;
    cout << "Index " << result2 << " contains: " << (result2 != -1 ? to_string(numbers[result2]) : "not found") << endl;
    cout << "Index " << result3 << " contains: " << (result3 != -1 ? to_string(numbers[result3]) : "not found") << endl;

  
}

int main() {
    Queue_Func();
    Recursive_Func();
    return 0;
}
