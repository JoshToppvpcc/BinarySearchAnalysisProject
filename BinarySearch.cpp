#include <iostream>
#include <vector>
#include <algorithm>

// Recursive binary search function
int recursiveBinarySearch(const std::vector<int>& vec, int target, int left, int right) {
    if (left > right) return -1; // Base case: target not found
    int mid = left + (right - left) / 2;
    if (vec[mid] == target) return mid;
    if (vec[mid] > target) return recursiveBinarySearch(vec, target, left, mid - 1);
    return recursiveBinarySearch(vec, target, mid + 1, right);
}

// Iterative binary search function
int iterativeBinarySearch(const std::vector<int>& vec, int target) {
    int left = 0, right = vec.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] == target) return mid;
        if (vec[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1; // Target not found
}

// Sequential search function
int sequentialSearch(const std::vector<int>& vec, int target) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == target) return i;
    }
    return -1; // Target not found
}

// Function to print the vector contents
void printVector(const std::vector<int>& vec) {
    for (int val : vec) std::cout << val << " ";
    std::cout << std::endl;
}

int main() {
    // Fill the vector with test data
    std::vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::sort(vec.begin(), vec.end()); // Ensure the vector is sorted

    int target1 = 3; // Item in the list
    int target2 = 10; // Item not in the list

    // Output the vector contents
    std::cout << "Vector contents: ";
    printVector(vec);

    // Recursive Binary Search
    int index = recursiveBinarySearch(vec, target1, 0, vec.size() - 1);
    std::cout << "Recursive Binary Search for " << target1 << ": ";
    if (index != -1)
        std::cout << "found at location " << index << std::endl;
    else
        std::cout << "not found, return value is " << index << std::endl;

    index = recursiveBinarySearch(vec, target2, 0, vec.size() - 1);
    std::cout << "Recursive Binary Search for " << target2 << ": ";
    if (index != -1)
        std::cout << "found at location " << index << std::endl;
    else
        std::cout << "not found, return value is " << index << std::endl;

    // Iterative Binary Search
    index = iterativeBinarySearch(vec, target1);
    std::cout << "Iterative Binary Search for " << target1 << ": ";
    if (index != -1)
        std::cout << "found at location " << index << std::endl;
    else
        std::cout << "not found, return value is " << index << std::endl;

    index = iterativeBinarySearch(vec, target2);
    std::cout << "Iterative Binary Search for " << target2 << ": ";
    if (index != -1)
        std::cout << "found at location " << index << std::endl;
    else
        std::cout << "not found, return value is " << index << std::endl;

    // Sequential Search
    index = sequentialSearch(vec, target1);
    std::cout << "Sequential Search for " << target1 << ": ";
    if (index != -1)
        std::cout << "found at location " << index << std::endl;
    else
        std::cout << "not found, return value is " << index << std::endl;

    index = sequentialSearch(vec, target2);
    std::cout << "Sequential Search for " << target2 << ": ";
    if (index != -1)
        std::cout << "found at location " << index << std::endl;
    else
        std::cout << "not found, return value is " << index << std::endl;

    return 0;
}
