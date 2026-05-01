#include <iostream>
using namespace std;

// Helper function to swap two values
void swapHeapValues(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Restore the max-heap at index i
void heapifyMax(int arr[], int n, int i) {
    // The current root is the largest value
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check if left child is larger than the current largest
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    // Check if right child is larger than current largest
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    // If one child is larger, swap and continue heap
    if (largest != i) {
        swapHeapValues(arr[i], arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Build the max heap from the unsorted array
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyMax(arr, n, i);
    }

    // Move the largest element to the end, then fix the heap.
    for (int i = n - 1; i > 0; i--) {
        swapHeapValues(arr[0], arr[i]);
        heapifyMax(arr, i, 0);
    }
}
