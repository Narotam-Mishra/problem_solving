
// Very Very Important Question

// Problem link - https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/ 

#include<bits/stdc++.h>
using namespace std;

// merge sorted array
vector<pair<int, int>> mergeTask(vector<pair<int, int>> &left, vector<pair<int, int>> &right, vector<int> &res){
    int i = 0, j = 0;
    vector<pair<int, int>> sortedArr;

    // compare element from both left and right array and merge
    while (i < left.size() || j < right.size()){
        // If the element from the left array is smaller or equal, add it to the sorted array
        if (j == right.size() || (i < left.size() && left[i].first <= right[j].first)){
            sortedArr.push_back(left[i]);

            // Count smaller elements from the right side by adding the current count (j) to result
            res[left[i].second] += j;
            i++;
        }
        else{
            sortedArr.push_back(right[j]);
            j++;
        }
    }
    return sortedArr;
}

// recursive call to mergeSort() function
vector<pair<int, int>> mergeSort(vector<pair<int, int>> &arr, vector<int> &res){
    // Base case: array of 1 element is always sorted, hence return
    if (arr.size() == 1)
        return arr;

    // calculate mid and recurively sort left and right half of array
    int mid = (int)arr.size() / 2;

    // recurively sort left and right half of array
    vector<pair<int, int>> leftArr(arr.begin(), arr.begin() + mid);
    vector<pair<int, int>> rightArr(arr.begin() + mid, arr.end());

    leftArr = mergeSort(leftArr, res);
    rightArr = mergeSort(rightArr, res);

    // merge both arrays and return
    return mergeTask(leftArr, rightArr, res);
}

vector<int> countSmaller(vector<int> &nums){
    int n = nums.size();
    // Initialize result array with 0s
    vector<int> res(n, 0);

    // create a vector of pairs where each pair contains the number and its original index
    vector<pair<int, int>> indexedNums;

    for (int i = 0; i < n; i++){
        indexedNums.push_back({nums[i], i});
    }

    // Perform merge sort and count smaller elements
    mergeSort(indexedNums, res);
    return res;
}

int main(){
    vector<int> nums = {5,2,6,1};
    // vector<int> nums = {2,0,1};

    vector<int> ans = countSmaller(nums);
    for(int num : ans){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}