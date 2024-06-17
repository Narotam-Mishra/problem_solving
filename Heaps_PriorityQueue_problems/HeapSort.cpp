
// Implement Heap sort using Heaps

#include<bits/stdc++.h>
using namespace std;

// utility method to build heap
// to heapify a subtree rooted with node i which is an index in arr[]
void heapify(vector<int>& arr, int n, int idx){
    // intilize largest as root
    int largest = idx;

    // find left and right child index
    int lcIdx = 2*idx + 1;
    int rcIdx = 2*idx + 2;

    // if left child is larger than root
    if (lcIdx < n && arr[lcIdx] > arr[largest]) {
        largest = lcIdx;
    }

    // if right child is larger than root
    if (rcIdx < n && arr[rcIdx] > arr[largest]) {
        largest = rcIdx;
    }

    // if largest is not root
    if (largest != idx) {
        // then swap
        swap(arr[idx], arr[largest]);

        // recursively heapify the affected sub-tree
        heapify(arr, n, largest);
        return;
    }
}

// utility function to perform heap sort
void heapSort(vector<int>& arr){
    int size = arr.size();

    // build heap from first none-leaf node
    int first_non_leftNode_idx = size / 2 - 1;
    for (int i = first_non_leftNode_idx; i >= 0; i--) {
        heapify(arr, size, i);
    }

    // one by one extract an element from heap
    for(int i = size - 1; i > 0; i--){
        // since we have build max-heap, so move current root to end
        // swapping
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void printVectorArray(vector<int>& arr){
    cout<<"Sorted array using heap sort is: ";
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {12, 7, 11, 5, 17, 6, 13};
    heapSort(arr);
    printVectorArray(arr);  
    return 0;
}