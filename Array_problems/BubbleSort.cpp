
// sort the array by using Bubble sort

#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int* arr, int n){
    for(int i=0; i<n; i++){
        bool isSwapped = false;

        for(int j=0; j<n-1-i; j++){
            if(arr[j] > arr[j+1]){
                // swap the numbers
                swap(arr[j], arr[j+1]);
                isSwapped = true;
            }
        }
        // If no swap is made in a pass, the array is already sorted
        if(!isSwapped) break;
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

    bubbleSort(arr,size);

    cout<< "Sorted Array: ";
    for(int num: arr){
        cout<< num << " ";
    }
}