
#include<bits/stdc++.h>
using namespace std;

int minOperations(vector<int>& nums, int k) {
    // using set to keep track of collected elements from 1 to k
    set<int> collection;
    int minOps = 0;

    // traverse the array from the last element to the first
    for(int i=nums.size()-1; i>=0; i--){
        // perform one operation (remove the last element)
        minOps++;

        // if the current element is between 1 and k, 
        // add it to the collected set
        if(nums[i] >= 1 && nums[i] <= k){
            collection.insert(nums[i]);
        }

        // if we've collected all elements from 1 to k, we can stop
        if(collection.size() == k) break;
    }
    // return the number of operations performed
    return minOps;
}

int main(){
    // vector<int> arr = {3,1,5,4,2};
    // int k = 2;

    vector<int> arr = {3,1,5,4,2};
    int k = 5;
    cout<<minOperations(arr, k);
    return 0;
}