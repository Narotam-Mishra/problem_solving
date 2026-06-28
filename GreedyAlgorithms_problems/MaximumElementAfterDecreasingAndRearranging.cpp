
// Problem link - https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/description/?envType=daily-question&envId=2026-06-28

#include<bits/stdc++.h>
using namespace std;

int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    int n = arr.size();

    // handle edge case
    if(n == 1){
        return 1;
    }

    // step 1 - sort the array
    sort(arr.begin(), arr.end());

    if(arr[0] != 1){
        arr[0] = 1;
    }

    // keep track of maximum value
    int maxVal = -1;

    // step 2 - iterate on each number of array, `arr`
    for(int i=1; i<n; i++){
        // step 3 - check and perform the given operation
        if(abs(arr[i] - arr[i-1]) > 1){
            arr[i] = arr[i-1] + 1;
        }

        maxVal = max(maxVal, arr[i]);
    }

    // step 4 - return maximum possible value
    return maxVal;
}

int main(){
    // vector<int> arr = {2,2,1,2,1};

    // vector<int> arr = {100, 1, 1000};

    vector<int> arr = {1,2,3,4,5};
    cout<<maximumElementAfterDecrementingAndRearranging(arr);
    return 0;
}