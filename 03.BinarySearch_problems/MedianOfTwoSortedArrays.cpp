
// Problem link - https://leetcode.com/problems/median-of-two-sorted-arrays/

// Approach - Brute Force Method

#include<bits/stdc++.h>
using namespace std;

vector<int> mergeSortedArrays(vector<int> &arr1, vector<int> &arr2, int m, int n){
    int i = 0, j = 0, k = 0;

    vector<int> res(m + n, 0);
    while (i < m && j < n){
        if (arr1[i] < arr2[j]){
            res[k] = arr1[i];
            k++;
            i++;
        }
        else{
            res[k] = arr2[j];
            k++;
            j++;
        }
    }

    // if any element left in arr1
    while (i < m){
        res[k] = arr1[i];
        k++;
        i++;
    }

    // if any element left in arr2
    while (j < n){
        res[k] = arr2[j];
        k++;
        j++;
    }
    // returned merged array
    return res;
}

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2){
    int m = nums1.size();
    int n = nums2.size();

    vector<int> mergedArr = mergeSortedArrays(nums1, nums2, m, n);
    int size = mergedArr.size();
    int mid = size / 2;

    // if array length is even
    if (size % 2 == 0){
        double f = (double)mergedArr[mid];
        double s = (double)mergedArr[mid - 1];
        return (f + s) / 2;
    }
    else{
        return (double)mergedArr[mid];
    }
}

int main(){
    vector<int> arr1 = {1,2};
    vector<int> arr2 = {3,4};
    double ans = findMedianSortedArrays(arr1, arr2);
    cout<<ans<<endl;
    return 0;
}