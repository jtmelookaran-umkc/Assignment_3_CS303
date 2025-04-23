#include "Insertion.h"
using namespace std;

//Function for utilizing the insertion sort based on queue functions we have
static void insertionSortQueue(Queue<int>& inputQueue) {

    Queue<int> sortedQueue;

    while (!inputQueue.empty()) {
        int current = inputQueue.front();
        inputQueue.pop();

        // Move items from sortedQueue to a tempQueue until we find correct spot
        Queue<int> tempQueue;
        bool inserted = false;

        while (!sortedQueue.empty()) {
            int sortedFront = sortedQueue.front();
            if (!inserted && current < sortedFront) {
                tempQueue.push(current);  // Insert in correct position
                inserted = true;
            }
            tempQueue.push(sortedFront);
            sortedQueue.pop();
        }

        if (!inserted) {
            // If current is largest, insert at the end
            tempQueue.push(current);
        }

        // Move everything back to sortedQueue
        while (!tempQueue.empty()) {
            sortedQueue.push(tempQueue.front());
            tempQueue.pop();
        }
    }

    // Copy  SortedQueue back into InputQueue
    while (!sortedQueue.empty()) {
        inputQueue.push(sortedQueue.front());
        sortedQueue.pop();
    }
}
