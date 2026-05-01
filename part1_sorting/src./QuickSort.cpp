#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;

    // move the middle element to the end for better efficiency
    // compared to last quicksort method
    int tempPivot = arr[mid];
    arr[mid] = arr[high];
    arr[high] = tempPivot;

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
