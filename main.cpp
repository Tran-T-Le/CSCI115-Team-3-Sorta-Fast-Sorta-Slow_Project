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

using namespace std;
//------------------------------------------------------TO-DO-------------------------------------------------------------------
/*Week 7	Mar 2–Mar 8	
Implement 3 simple sorts (Insertion/Selection/Bubble)
Define input generators (best/avg/worst)
Decide input sizes (n values) + repetitions
Code runs on small n; input generator produces intended cases
Week 8	Mar 9–Mar 15	
Implement Merge + Heap
Implement Quicksort (best version / randomized or median-of-3)
Validate correctness (unit tests)
All implemented sorts pass correctness tests on random + edge cases*/
//------------------------------------------------------------------------------------------------------------------------------

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

//void InsertionSort(int arr[], int n);
void oneArr(int* arr, int size);
//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------INT MAIN----------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
int main() {
    //srand(time(NULL));
    
    int algorithm;
    int size; //n is the size of the array
    int choice;

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

    

    int* arr = new int[size];
    oneArr(arr,size);
    
    cout << "Choose one of the following sorting algorithms: \n";
    cout << "[1]: Bubble Sort, [2]: Selection Sort, [3]: Insertion Sort, [4]: Merge Sort, [5]: Quick Sort, [6]: Heap Sort, [7]: Counting Sort, [8]: Radix Sort\n";

    cout << "Select " << endl;

    cin >> algorithm;


    if (algorithm == 1){

    } else if (algorithm == 2){

    } else if (algorithm == 3){
        insertionSort(arr, size);
    } else if (algorithm == 4){
        /* code */
    } else if (algorithm == 5){
        /* code */
    } else if (algorithm == 6){
        /* code */
    } else if (algorithm == 7){
        /* code */
    }else if (algorithm == 8){
        /* code */
    } else{
        cout << "\ninvalid input";
    }
    
    delete[] arr;
    return 0;
}