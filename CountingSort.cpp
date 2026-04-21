#include <iostream>
using namespace std;

// Find the largest value from the array
int countingMaxValue(int arr[], int n) {
    int maxValue = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }
    return maxValue;
}

// Count occurence and places each values into correct place
void countingSort(int arr[], int n) {
    if (n <= 1) {
        return;
    }

    // Find the maximum value in an array
    int maxValue = countingMaxValue(arr, n);

    // Create a count array to store values and an output array to store sorted result
    int* count = new int[maxValue + 1];
    int* output = new int[n];

    // Start all counts at 0
    for (int i = 0; i <= maxValue; i++) {
        count[i] = 0;
    }

    // Count how many times each value appears
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Turn counts into runing totals
    for (int i = 1; i <= maxValue; i++) {
        count[i] = count[i] + count[i - 1];
    }

    // Place value into the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Output and copy the sorted values into the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    
    // Free array memory
    delete[] count;
    delete[] output;
}
