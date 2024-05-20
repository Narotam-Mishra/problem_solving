
// sort array's elements using Randomized Quick sort

#include<bits/stdc++.h>
using namespace std;

void shuffleArray(int *arr, int s, int e){
    int i, j;

    // Seed for random number generation
    srand(time(NULL));
    for(i=e; i>0; i--){
        // This ensures that the generated random index j will be within the bounds of the array from 0 to i.
        j = rand() % (i+1);
        swap(arr[i], arr[j]);
    }
}

int findPivotIndexByArrayPartition(int *arr, int s, int e){
    int i = s-1, pivot = arr[e];

    // loop through each element to create partiton into two halves of array
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

void randomizedQuickSort(int *arr, int start, int end){
    // Base case: if start and end index are equal then return
    if(start >= end){
        return;
    }else{
        // recursively sort array by finding pivot element
        // Step1 : find pivot element's index using findPivotIndexByArrayPartition() method
        int pivotIndex = findPivotIndexByArrayPartition(arr, start, end);

        // Step - 2 & 3: after finding pivot element's index, recursively sort two partitions of arrays
        randomizedQuickSort(arr, start, pivotIndex-1);
        randomizedQuickSort(arr, pivotIndex+1, end);
    }
}

int main(){
    int arr[] = {2,7,6,3,5,1,4};
    // int arr[] = {1,2,3,4,5,6,7};
    
    int size = sizeof(arr)/sizeof(int);

    cout<<"Original Input Array: ";
    for(int num : arr){
        cout<<num<<" ";
    }

    cout<<endl;
    shuffleArray(arr, 0, size-1);

    cout<<"Shuffled Unsorted Array: ";
    for(int num : arr){
        cout<<num<<" ";
    }

    cout<<endl;
    randomizedQuickSort(arr, 0, size-1);

    cout<<"Sorted Array: ";
    for(int num : arr){
        cout<<num<<" ";
    }
    return 0;
}