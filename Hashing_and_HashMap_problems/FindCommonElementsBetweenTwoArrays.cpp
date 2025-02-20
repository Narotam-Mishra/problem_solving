
// Problem link - https://leetcode.com/problems/find-common-elements-between-two-arrays/?envType=problem-list-v2&envId=hash-table

#include<bits/stdc++.h>
using namespace std;

vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
    // step 1 - initialize counters for the answers
    int ans1 = 0, ans2 = 0;

    // step 2 - add nums1 & nums2 numbers in arr1 & arr2 respectively for best lookup
    vector<bool> arr1(101, false);
    for (int num : nums1) {
        arr1[num] = true;
    }
    vector<bool> arr2(101, false);
    for (int num : nums2) {
        arr2[num] = true;
    }

    // step 3 - count how many elements in nums1 exist in arr2 and vice versa
    for (int num : nums1) {
        if (arr2[num] == true) {
            ans1++;
        }
    }

    for (int num : nums2) {
        if (arr1[num] == true) {
            ans2++;
        }
    }

    // step 4 - return the results as an array
    return vector<int>{ans1, ans2};
}

void printVector(vector<int>& vec){
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout<<vec[i];
        if (i < vec.size() - 1) {
            cout<<",";
        }
    }
    cout<< "]" <<endl;
}

int main(){
    // vector<int> nums1 = {2, 3, 2};
    // vector<int> nums2 = {1, 2};

    // vector<int> nums1 = {4,3,2,3,1};
    // vector<int> nums2 = {2,2,5,2,3,6};

    vector<int> nums1 = {3,4,2,3};
    vector<int> nums2 = {1,5};
    vector<int> res = findIntersectionValues(nums1, nums2);
    printVector(res);
    return 0;
}