/********************************************************************************
Author(s) Group 3: Gurleen Kaur, Tran Le, Vanessa Salinas, Vickydel Gutierrez
Course: CSCI 115 Project
Assignment: Sorting Algorithms
*******************************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "SelectionSort.cpp"
#include "InsertionSort.cpp"
#include "QuickSort.cpp"
#include "BubbleSort.cpp"
#include "CountingSort.cpp"
#include "HeapSort.cpp"
#include "RadixSort.cpp"
#include "MergeSort.cpp"

using namespace std;
//------------------------------------------------------TO-DO-------------------------------------------------------------------
/* 
Finalize timing harness and run benchmarks for all algorithms and input types.
run best-case experiements (all sorts, chosen n's) 
start plotting time v.s. n graphs for best case for all algorithms
results can be typed into google doc labeled as "CSCI 115 Final Project (final stretch) Assignments"

*/
//------------------------------------------------------------------------------------------------------------------------------

// array of sorted values
void bestCaseArr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
}

// array of reverse sorted values
void worstCaseArr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = size - i;
    }
}

// array of random values <size
void randomArr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        
        arr[i] = rand()%size;
    }
}

// random values of 7 digits 
void randomLargeArr(int* arr, int size) {
    for (int i = 0; i < size; i++) {

        arr[i] = rand()+1000000 % (10000000);
    }
}

// array of random values where one is much larger than the others
// radix worst case
void oneArr(int* arr, int size) {
    arr[size - 1] = 1000000;
    for (int i = 0; i < size-1; i++) {

        arr[i] = rand()%1000;
    }
}

void InsertionSort(int arr[], int n);
void oneArr(int* arr, int size);
//--------------------------------------------------------------------------------
//--------------Printing small function for testing purposes----------------------
//--------------------------------------------------------------------------------

// only prints the array if the size is less than or equal to 20
void printSmall(int arr[], int n) {
    int limit = min(n, 20);
    for (int i = 0; i < limit; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
//------------------------------------------------------------------------------------
//-----------------------------Helper functions for testing, correctness unit test----
//------------------------------------------------------------------------------------
//helper functions to check if the array is sorted and if two arrays are equal
bool arraysEqual(int* a, int* b, int n) {
    for (int i = 0; i < n; i++)
        if (a[i] != b[i]) return false;
    return true;
}
// checks if the array is sorted in non-decreasing order
bool isSorted(int arr[], int n) {
    for (int i = 1; i < n; i++)
        if (arr[i] < arr[i - 1]) return false;
    return true;
}
//------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------WRAPPERS----------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------

/*void mergeSortWrapper(int arr[], int n) {
    mergeSort(arr, 0, n - 1);
}
*/

/*void radixSortWrapper(int arr[], int n) { // this wrapper is dependant on what radix sort takes as input, if (arr,n) we use this wrapper,
    radixSort(arr, n); // if radix sort takes (arr, size, maxVal) then i will need to update this
}
*/


void quickSortWrapper(int arr[], int n) {
    quickSort(arr, 0, n - 1);
}


void heapSortWrapper(int arr[], int n) {
    heapSort(arr, n);
}

void testSort(void (*sortFunc)(int[], int), string name) {
    cout << "Testing " << name << "...\n";

    int sizes[] = {0, 1, 5, 10, 100};
    for (int s : sizes) {
        int* arr = new int[s];
        int* ref = new int[s];

        for (int i = 0; i < s; i++) {
            arr[i] = rand() % 1000;
            ref[i] = arr[i];
        }

        sort(ref, ref + s);
        sortFunc(arr, s);

        if (arraysEqual(arr, ref, s))
            cout << "  ✔ Passed size " << s << endl;
        else
            cout << "  ❌ Failed size " << s << endl;

        delete[] arr;
        delete[] ref;
    }
}



//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------INT MAIN----------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
int main() {
    //srand(time(NULL));
    cout << "Running correctness tests...\n";

    testSort(insertionSort, "Insertion Sort");
    testSort(selectionSort, "Selection Sort");
    testSort(bubbleSort, "Bubble Sort");
    testSort(countingSort, "Counting Sort");
    //testSort(mergeSortWrapper, "Merge Sort");
    //testSort(radixSortWrapper, "Radix Sort");
    testSort(heapSortWrapper, "Heap Sort");
    testSort(quickSortWrapper, "Quick Sort");


    cout << "Correctness tests complete.\n\n";

    int algorithm; //algorithm is the user's choice for the sorting algorithm
    int size; //n is the size of the array
    int choice; //choice is the user's choice for the size of the array

    cout << "Choose the size of your array: \n";
    cout << "[1]: 100 [2]: 1,000 [3]: 10,000 [4]: 100,000 [5]: 500,000 [6]: 1,000,000 \n";

    cin >> choice;

    if (choice == 1){
        size = 100;
    } else if (choice == 2){
        size = 1000;
    } else if (choice == 3){
        size = 10000;
    } else if(choice == 4){
        size = 100000;
    } else if(choice == 5){
        size = 500000;
    } else if(choice == 6){
        size = 1000000;
    } else{
        cout << "invlaid choice.\n";
        return 0;
    }
    
    int* arr = new int[size]; // create array of size n
    // oneArr(arr,size); // fill array with random values where one is much larger than the others
    
    cout << "Choose input type:\n";
    cout << "[1] Best case (sorted)\n";
    cout << "[2] Average case (random)\n";
    cout << "[3] Worst case (reverse sorted)\n";


    int inputType;
    cin >> inputType;

    if (inputType == 1) bestCaseArr(arr, size);
    else if (inputType == 2) randomArr(arr, size);
    else if (inputType == 3) worstCaseArr(arr, size);
    else {
    cout << "Invalid input type.\n";
    return 0;
    }
    
    cout << "Choose one of the following sorting algorithms: \n";
    cout << "[1] Bubble Sort\n";
    cout << "[2] Selection Sort\n";
    cout << "[3] Insertion Sort\n";
    cout << "[4] Merge Sort\n";
    cout << "[5] Quick Sort\n";
    cout << "[6] Heap Sort\n";
    cout << "[7] Counting Sort\n";
    cout << "[8] Radix Sort\n";

    cin >> algorithm;


    if (algorithm == 1){
        clock_t start = clock();
        bubbleSort(arr, size);
        clock_t end = clock();
        double elapsed = double(end - start) * 1000.0 / CLOCKS_PER_SEC;
        cout << "Time: " << elapsed << " ms\n";

    } else if (algorithm == 2){
        clock_t start = clock();
        selectionSort(arr, size);
        clock_t end = clock();
        double elapsed = double(end - start) * 1000.0 / CLOCKS_PER_SEC;
        cout << "Time: " << elapsed << " ms\n";

    } else if (algorithm == 3){
        clock_t start = clock();
        insertionSort(arr, size);
        clock_t end = clock();
        double elapsed = double(end - start) * 1000.0 / CLOCKS_PER_SEC;
        cout << "Time: " << elapsed << " ms\n";

    } else if (algorithm == 4){
        clock_t start = clock();
        mergeSort(arr, 0, size - 1);
        clock_t end = clock();
        double elapsed = double(end - start) * 1000.0 / CLOCKS_PER_SEC;
        cout << "Time: " << elapsed << " ms\n";
    } else if (algorithm == 5){
        clock_t start = clock();
        quickSort(arr, 0, size-1);
        clock_t end = clock();
        double elapsed = double(end - start) * 1000.0 / CLOCKS_PER_SEC;
        cout << "Time: " << elapsed << " ms\n";
    } else if (algorithm == 6){
        clock_t start = clock();
        heapSort(arr, size);
        clock_t end = clock();
        double elapsed = double(end - start) * 1000.0 / CLOCKS_PER_SEC;
        cout << "Time: " << elapsed << " ms\n";
    } else if (algorithm == 7){
        clock_t start = clock();
        countingSort(arr, size);
        clock_t end = clock();
        double elapsed = double(end - start) * 1000.0 / CLOCKS_PER_SEC;
        cout << "Time: " << elapsed << " ms\n";
    }else if (algorithm == 8){
        clock_t start = clock();
        oneArr(arr,size); // fill array with random values where one is much larger than the others
        radixSort(arr, size);
        clock_t end = clock();
        double elapsed = double(end - start) * 1000.0 / CLOCKS_PER_SEC;
        cout << "Time: " << elapsed << " ms\n";
    } else{
        cout << "\ninvalid input";
    }
    printSmall(arr, size);

    delete[] arr;// free memory allocated for array


    return 0;
}
