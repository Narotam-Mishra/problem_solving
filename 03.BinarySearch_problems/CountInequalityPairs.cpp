
// 2426. Number of Pairs Satisfying Inequality
// Problem Link - https://leetcode.com/problems/number-of-pairs-satisfying-inequality/description/

#include<bits/stdc++.h>
using namespace std;

long long pairCount;

void countInequalitiyPairs(vector<int>& arr, int s, int mid, int e, int diff){
    int i = s, j = mid + 1;

    // count pairs as per given equation
    while(i<=mid && j<=e){
        if(arr[i] <= arr[j] + diff){
            //  if above condition satisfy 
            // then all values from nums[r] to nums[end] will satisfy the inequalities condition
            pairCount += (e - j + 1);
            i++;
        }else{
            j++;
        }
    }
    return;
}

void mergeSortedArray(vector<int>& arr, int s, int mid, int e){
    int i = s, j = mid+1, k=0;
    vector<int> temp(e-s+1);

    // compare and merge
    while(i <= mid && j <= e){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
        }
    }

    // copy back remaining elements from left sub array
    while(i <= mid){
        temp[k++] = arr[i++];
    }

    // copy back remaining elements from left sub array
    while(j <= e){
        temp[k++] = arr[j++];
    }

    // copy back temp array elements to original array arr
    for(int id=0; id<temp.size(); id++){
        arr[s+id] = temp[id];
    }
}

void mergeSort(vector<int>& arr, int s, int e, int diff){
    // Base Case:
    if(s == e) return;

    // calculate mid
    int mid = (s + e)/2;

    // recursively call mergeSort() on left half of array
    mergeSort(arr, s, mid, diff);

    // recursively call mergeSort() on left half of array
    mergeSort(arr, mid+1, e, diff);

    // Count inequalities pairs
    countInequalitiyPairs(arr, s, mid, e, diff);

    // merge sorted array
    mergeSortedArray(arr, s, mid, e);
    return;
}

long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
    pairCount = 0;

    int n = nums1.size();
    vector<int> diffArr(n);

    for(int i=0; i<n; i++){
        diffArr[i] = nums1[i] - nums2[i];
    }
    mergeSort(diffArr,0, n-1, diff);
    return pairCount;
}

int main(){
    // vector<int> arr1 = {3,2,5};
    // vector<int> arr2 = {2,2,1};
    // int diff = 1;

    vector<int> arr1 = {-4, -4, 4, -1, -2, 5};
    vector<int> arr2 = {-2, 2, -1, 4, 4, 3};
    int diff = 1;

    long long ans = numberOfPairs(arr1, arr2, diff);
    cout<<ans<<endl;
    return 0;
}