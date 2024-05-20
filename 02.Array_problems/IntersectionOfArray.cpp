
// Problem link - https://leetcode.com/problems/intersection-of-two-arrays/description/

#include<bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
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
            // found first common element, also we have to make sure we are not duplicating the same element 
            // as we need to store unique element in result array res[]
            if(res.size() == 0 || res.back() != nums1[i]){
                res.push_back(nums1[i]);
            }
            i++;
            j++;
        }
    }
    return res;
}

vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> numSet(nums1.begin(), nums1.end());
    unordered_set<int> intersectionSet;

    // iterate on nums2 array and check if nums2 array item is present in numSet
    // if it is present then add it in intersectionSet
    for(int num : nums2){
        if(numSet.count(num)){
            intersectionSet.insert(num);
        }
    }

    vector<int> res(intersectionSet.begin(), intersectionSet.end());
    return res;
}

int main(){
    vector<int> arr1 = {4,9,5};
    vector<int> arr2 = {9,4,9,8,4};
    // vector<int> ans = intersection(arr1, arr2);

    vector<int> ans = intersection1(arr1, arr2);
    for(int num : ans){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}