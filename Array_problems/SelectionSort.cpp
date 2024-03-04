
// sort array's items using Selection sort

#include<bits/stdc++.h>
using namespace std;

int findMinIndex(int* arr, int i, int size){
    int minIndex = i;
    
    for(int j = i+1; j<size; j++){
        if(arr[j] < arr[minIndex]){
            minIndex = j;
        }
    }
    return minIndex;
}

void selectionSort(int* arr, int n){
    for(int i=0; i<n; i++){
        int minIndex = findMinIndex(arr, i, n);
        if(i != minIndex){
            swap(arr[minIndex], arr[i]);
        }
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

    selectionSort(arr,size);

    cout<< "Sorted Array: ";
    for(int num: arr){
        cout<< num << " ";
    }
}