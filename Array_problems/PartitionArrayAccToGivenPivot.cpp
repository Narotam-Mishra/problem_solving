
// Problem link - https://leetcode.com/problems/partition-array-according-to-given-pivot/description/?envType=daily-question&envId=2026-06-08

#include<bits/stdc++.h>
using namespace std;

vector<int> pivotArray(vector<int>& nums, int pivot) {
    // three buckets to hold elements by category
    vector<int> less_than, equal_to, greater_than; 
    
    // step 1 - scan element from left to right
    for(int num : nums){
        if(num < pivot){
            less_than.push_back(num);
        }else if(num > pivot){
            greater_than.push_back(num);
        }else{
            equal_to.push_back(num);
        }
    }

    // step 2 - merge all three buckets into nums
    int i = 0;
    for(int num : less_than){
        nums[i++] = num;
    }
    for(int num : equal_to){
        nums[i++] = num;
    }
    for(int num : greater_than){
        nums[i++] = num;
    }

    // step 3 - return final nums
    return nums;
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
    vector<int> nums = {9,12,5,10,14,3,10};
    int pivot = 10;
    vector<int> res = pivotArray(nums, pivot);
    printVector(res);
    return 0;
}