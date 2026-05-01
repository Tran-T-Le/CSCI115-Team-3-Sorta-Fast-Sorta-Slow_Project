#include <iostream>
using namespace std;

// Find the largest value in the array
int radixMaxValue(int arr[], int n) {
    int maxValue = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }

    return maxValue;
}

// Counting sort based on one digit position
void countingSortByDigit(int arr[], int n, int exp) {
    int* output = new int[n];
    int count[10] = {0};

    // Count each digit
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Turn counts into running totals
    for (int i = 1; i < 10; i++) {
        count[i] = count[i] + count[i - 1];
    }

    // Build output array from right to left for stability
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy sorted values back into original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    delete[] output;
}

// Radix Sort using LSD method
void radixSort(int arr[], int n) {
    if (n <= 1) {
        return;
    }

    int maxValue = radixMaxValue(arr, n);

    // Sort by ones, tens, hundreds, etc.
    for (int exp = 1; maxValue / exp > 0; exp = exp * 10) {
        countingSortByDigit(arr, n, exp);
    }
}
