#include <vector>

using namespace std;

// Helper function for recursively finding the last occurrence of target
// Parameters:
// - vec: the vector to search in
// - target: the value to find
// - currentIndex: the current index being examined
// - lastFound: the index of the last occurrence found so far (-1 if not found yet)
template <typename T>
int findLastOccurrenceHelper(const vector<T>& vec, const T& target, int currentIndex, int lastFound) {
    // Base case: reached the end of the vector
    if (currentIndex < 0) {
        return lastFound;
    }

    // If target found at current position, update lastFound
    if (vec[currentIndex] == target) {
        return findLastOccurrenceHelper(vec, target, currentIndex - 1, currentIndex);
    }

    // Continue search without updating lastFound
    return findLastOccurrenceHelper(vec, target, currentIndex - 1, lastFound);
}

// Main function to find the last occurrence of target in vector
// Returns the index of the last occurrence, or -1 if not found
template <typename T>
int findLastOccurrence(const vector<T>& vec, const T& target) {
    // Start search from the end of the vector
    return findLastOccurrenceHelper(vec, target, vec.size() - 1, -1);
}

// Alternative implementation that searches from start to end
// This is more elegant but may be less intuitive
template <typename T>
int findLastOccurrenceAlt(const vector<T>& vec, const T& target, int index = 0) {
    // Base case: reached the end of the vector
    if (index >= vec.size()) {
        return -1;
    }

    // Recursively search the rest of the vector first
    int lastIndex = findLastOccurrenceAlt(vec, target, index + 1);

    // If we found the target in the rest of the vector, return that index
    // Otherwise, check if the current element matches the target
    if (lastIndex != -1) {
        return lastIndex;
    }
    else if (vec[index] == target) {
        return index;
    }
    else {
        return -1;
    }
}