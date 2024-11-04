#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>

const int N = 1000000; // Number of items in the array
double SumRBS = 0.0; // Accumulator for Recursive Binary Search times
double SumIBS = 0.0; // Accumulator for Iterative Binary Search times
double SumSeqS = 0.0; // Accumulator for Sequential Search times

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

// Function to fill the vector with random values between 1 and 100
void fillVectorWithRandomValues(std::vector<int>& vec, int size) {
    for (int i = 0; i < size; i++) {
        vec.push_back(rand() % 100 + 1); // Random number between 1 and 100
    }
}

int main() {
    srand(time(0)); // Seed random number generator

    for (int i = 0; i < 10; i++) {
        std::vector<int> vec;
        fillVectorWithRandomValues(vec, N); // Fill vector with random numbers
        std::sort(vec.begin(), vec.end()); // Ensure vector is sorted for binary search

        int target = rand() % 100 + 1; // Random target between 1 and 100

        // Recursive Binary Search timing
        auto start = std::chrono::high_resolution_clock::now();
        recursiveBinarySearch(vec, target, 0, vec.size() - 1);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::micro> duration = end - start;
        SumRBS += static_cast<double>(duration.count());

        // Iterative Binary Search timing
        start = std::chrono::high_resolution_clock::now();
        iterativeBinarySearch(vec, target);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        SumIBS += static_cast<double>(duration.count());

        // Sequential Search timing
        start = std::chrono::high_resolution_clock::now();
        sequentialSearch(vec, target);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        SumSeqS += static_cast<double>(duration.count());
    }

    // Output average running times
    std::cout << "Average Running Time for Recursive Binary Search in microseconds: " << SumRBS / 10 << std::endl;
    std::cout << "Average Running Time for Iterative Binary Search in microseconds: " << SumIBS / 10 << std::endl;
    std::cout << "Average Running Time for Sequential Search in microseconds: " << SumSeqS / 10 << std::endl;

    return 0;
}
