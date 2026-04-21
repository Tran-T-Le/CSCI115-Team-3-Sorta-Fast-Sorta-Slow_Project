#include <iostream>
using namespace std;

void swapHeapValues(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void heapifyMax(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swapHeapValues(arr[i], arr[largest]);
        heapifyMax(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyMax(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swapHeapValues(arr[0], arr[i]);
        heapifyMax(arr, i, 0);
    }
}
