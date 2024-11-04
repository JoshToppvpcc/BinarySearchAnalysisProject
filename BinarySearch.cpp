#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

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

// Function to fill the vector with random values between 1 and 100
void fillVectorWithRandomValues(std::vector<int>& vec, int size) {
    for (int i = 0; i < size; i++) {
        vec.push_back(rand() % 100 + 1); // Random number between 1 and 100
    }
}

int main() {
    srand(time(0)); // Seed random number generator

    std::vector<int> vec;
    int vectorSize = 10; // You can change the vector size here

    // Fill the vector with random values and sort it
    fillVectorWithRandomValues(vec, vectorSize);
    std::sort(vec.begin(), vec.end());

    // Randomly generate a target value between 1 and 100
    int target = rand() % 100 + 1;

    // Output the vector contents
    std::cout << "Vector contents: ";
    printVector(vec);

    // Recursive Binary Search
    int index = recursiveBinarySearch(vec, target, 0, vec.size() - 1);
    std::cout << "Recursive Binary Search for target " << target << ": ";
    if (index >= 0)
        std::cout << "found at location " << index << std::endl;
    else
        std::cout << "was not found" << std::endl;

    // Iterative Binary Search
    index = iterativeBinarySearch(vec, target);
    std::cout << "Iterative Binary Search for target " << target << ": ";
    if (index >= 0)
        std::cout << "found at location " << index << std::endl;
    else
        std::cout << "was not found" << std::endl;

    // Sequential Search
    index = sequentialSearch(vec, target);
    std::cout << "Sequential Search for target " << target << ": ";
    if (index >= 0)
        std::cout << "found at location " << index << std::endl;
    else
        std::cout << "was not found" << std::endl;

    return 0;
}
