
// Problem link - https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
// Approach - Two pointers


#include<bits/stdc++.h>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    // two pointers i and j to interate on array
    int i = 0, j = 0;

    vector<int> res;
    while (i < nums1.size() && j < nums2.size()){
        if(nums1[i] < nums2[j]){
            i++;
        }else if(nums1[i] > nums2[j]){
            j++;
        }else{
            // found first common element, 
            res.push_back(nums1[i]);
            i++;
            j++;
        }
    }
    return res;
}

vector<int> intersect1(vector<int>& nums1, vector<int>& nums2) {
    // HashMap to store counts of numbers
    unordered_map<int, int> map;

    // result, res vector to store intersecting elements
    vector<int> res;

    // count frequecy of each element of nums1 array
    for(int num : nums1){
        map[num]++;
    }

    // Check for intersecting elements in nums2 and decrement counts in map
    for(int num : nums2){
        if(map[num] > 0){
            res.push_back(num);
            map[num]--;
        }
    }

    return res;
}

int main(){
    // vector<int> arr1 = {4,9,5};
    // vector<int> arr2 = {9,4,9,8,4};

    vector<int> arr1 = {1,2,2,1};
    vector<int> arr2 = {2,2};
    
    vector<int> ans = intersect1(arr1, arr2);
    for(int num : ans){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}