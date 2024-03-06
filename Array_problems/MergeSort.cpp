
// sort array's elements using merge sort algorithm

#include<bits/stdc++.h>
using namespace std;

vector<int> mergeArray(vector<int>& left, vector<int>& right){
    int m = left.size(), n = right.size();
    int i = 0, j = 0, k = 0;
    vector<int> resArr(m+n);

    // compare left and right array elements
    while(i < m && j < n){
        if(left[i] < right[j]){
            resArr[k] = left[i];
            i++;
            k++;
        }else{
            // right[j] < left[i]
            resArr[k] = right[j];
            j++;
            k++;
        }
    }

    // if right array is exhausted, copy remaining elements from left array
    while(i < m){
        resArr[k] = left[i];
        i++;
        k++;
    }

    // if left array is exhausted, copy remaining elements from right array
    while(j < n){
        resArr[k] = right[j];
        j++;
        k++;
    }

    return resArr;
}

vector<int> mergeSortHelper(vector<int> arr, int start, int end){
    // Base case: array of single item is always sorted
    if(start == end){
        vector<int> res(1);
        res[0] = arr[start];
        return res;
    }else{
        int mid = (int)(start + end)/2;
        // Recursive case

        // Recursive case1 : recursive call to left part of array
        vector<int> left = mergeSortHelper(arr, start, mid);

        // Recursive case2 : recursive call to right part of array
        vector<int> right = mergeSortHelper(arr, mid+1, end);

        // merge arrays
        return mergeArray(left, right);
    }
}

int main(){
    vector<int> arr  = {7,1,6,2,5,3,4};
    cout<< "Unsorted Array: ";
    for(int num: arr){
        cout<< num << " ";
    }

    vector<int> ans = mergeSortHelper(arr, 0, arr.size()-1);
    cout<<endl;

    cout<< "Sorted Array: ";
    for(int num: ans){
        cout<< num << " ";
    }
    return 0;
}