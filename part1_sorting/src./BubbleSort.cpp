#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {

    bool swapped;

    // Outer loop for passes
    for (int i = 0; i < n - 1; i++) {

        swapped = false;

        // Inner loop for comparisons
        for (int j = 0; j < n - i - 1; j++) {

            // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {

                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = true;
            }
        }

        // If no swaps happened, array is sorted
        if (swapped == false) {
            break;
        }
    }
}
