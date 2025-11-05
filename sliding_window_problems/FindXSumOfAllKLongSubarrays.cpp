
// Problem link - https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/description/?envType=daily-question&envId=2025-11-04

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int findTopXSum(unordered_map<int, int>& mp, int x){
    // using min-heap
    priority_queue<P, vector<P>, greater<P>> pq;

    for(auto &it : mp){
        pq.push({it.second, it.first});

        // remove smallest element from top
        if(pq.size() > x){
            pq.pop();
        }
    }

    int sum = 0;
    while(!pq.empty()){
        auto [frq, val] = pq.top();
        pq.pop();

        sum += frq * val;
    }

    return sum;
}

vector<int> findXSum(vector<int>& nums, int k, int x) {
    int n = nums.size();

    // map to store frequency of each number of `nums`
    unordered_map<int, int> frqMap;

    // store final result in `res`;
    vector<int> res;

    // step 1 - using sliding window technique
    int i = 0 , j = 0;
    while(j < n){
        // step 2 - count frqequency
        frqMap[nums[j]]++;

        // step 3 - check window size reached `k` or not
        if(j - i + 1 == k){
            // step 4 - calculate and store result in `res`
            int s = findTopXSum(frqMap, x);
            res.push_back(s);

            // step 4 - shrink the window
            frqMap[nums[i]]--;
            if(frqMap[nums[i]] == 0){
                frqMap.erase(nums[i]);
            }
            i++;
        }

        // stp 5 - move to next window
        j++;
    }

    // step 6 - return final result `res`
    return res;
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
    // vector<int> nums = {1,1,2,2,3,4,2,3};
    // int k = 6, x = 2;

    vector<int> nums = {3,8,7,8,7,5};
    int k = 2, x = 2;
    vector<int> res = findXSum(nums, k, x);
    printVector(res);
    return 0;
}