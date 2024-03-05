
// sort the array's elements using Insertion sort

#include<bits/stdc++.h>
using namespace std;

void insertionSort(int* arr, int n){
    for(int i=1; i<n; i++){
        // array with single element is always sorted
        int currval = arr[i], j=0;

        for(j=i-1; j>=0; j--){
            // if previous value of array is greater than current value of array
            if(arr[j] > currval){
                // then shift previous value to the unsorted region of array
                arr[j+1] = arr[j];
            }else{
                // arr[j] <= currval
                break;
            }
        }
        arr[j+1] = currval;
    }
}

int main(){
    int arr[] = {7,3,5,1,4,2,6};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout<< "Unsorted Array: ";
    for(int num: arr){
        cout<< num << " ";
    }

    cout<<endl;

    insertionSort(arr,size);

    cout<< "Sorted Array: ";
    for(int num: arr){
        cout<< num << " ";
    }

    return 0;
}