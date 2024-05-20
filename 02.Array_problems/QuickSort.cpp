
/*

# sort the array using Quick sort algorithm

# Steps to sort array using Quick Sort :-
1). Find pivot elemnt in array using partition of array
2). Divide the array about pivot
3). Recursively sort the 2 parts of array

*/

#include<bits/stdc++.h>
using namespace std;

int findPivotIndexByArrayPartition(int *arr, int s, int e){
    // let us assume array's last element is pivot element
    int i = s-1, pivot = arr[e];

    // iterate over array elements and partition into two halves
    for(int j=s; j<e; j++){
        if(arr[j] < pivot){
            i++;
            // perform swap to bring smaller element to left of pivot element
            swap(arr[i], arr[j]);
        }
    }
    // bring pivot element to its correct place
    swap(arr[i+1], arr[e]);

    // return pivot element index
    return i+1;
}

void quickSort(int *arr, int l, int r){
    // Base case: if start and end index are equal then return
    if(l >= r){
        return;
    }
    //Step - 1: find pivot element's index using findPivotIndexByArrayPartition() method
    int pivotIndex = findPivotIndexByArrayPartition(arr, l, r);
    // Step - 2 & 3: after finding pivot element's index, recursively sort two partitions of arrays
    quickSort(arr, l, pivotIndex-1);
    quickSort(arr, pivotIndex+1, r);
}

int main(){
    int arr[] = {2,7,6,3,5,1,4};
    int size = sizeof(arr)/sizeof(int);

    cout<<"Unsorted Array: ";
    for(int num : arr){
        cout<<num<<" ";
    }

    cout<<endl;
    quickSort(arr, 0, size-1);

    cout<<"Sorted Array: ";
    for(int num : arr){
        cout<<num<<" ";
    }
    return 0;
}