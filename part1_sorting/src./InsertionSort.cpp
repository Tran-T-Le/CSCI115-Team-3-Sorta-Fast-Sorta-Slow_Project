#include <iostream>
using namespace std;

//n is the size of the array
void insertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        //key is the current element thats being compared to the sorted subarray
        int key = arr[i];
        int j = i - 1;

        //sorts in ascending order
        //the elements that are greater than the key will be moved
        //one position up in the array
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j -= 1;
        }
        //Places the key in the right position in the array
        arr[j+1] = key;
        
    }

    for(int k = 0; k < n; k++){
        cout << arr[k] << " ";
    }
    cout << endl;

}