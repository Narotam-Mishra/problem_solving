
// Problem link - https://leetcode.com/problems/maximize-happiness-of-selected-children/?envType=daily-question&envId=2025-12-25

#include<bits/stdc++.h>
using namespace std;

// Approach - 1 (using sorting)
long long maximumHappinessSum1(vector<int>& happiness, int k) {
    int n = happiness.size();

    // step 1 - sort happiness in descending order
    // since we have to maximise happiness
    sort(begin(happiness), end(happiness), greater<int>());

    // step 2 - keep track of number of child picked in `count` till now
    long long res = 0;
    int count = 0;
    for(int i=0; i<k; i++){
        // step 3 - calculate maximum happiness so far
        res += max(0, happiness[i] - count);
        count++;
    }

    // step 4 - return the maximum sum of the happiness values from `res`
    return res;
}

// Approach - 2 (using max Heap)
long long maximumHappinessSum(vector<int>& happiness, int k) {
    int n = happiness.size();

    // store final result in `res`
    long long res = 0;

    // step 1 - store happiness in max-Heap
    // since we have to maximise happiness
    priority_queue<int> pq;
    for(int h : happiness){
        pq.push(h);
    }

    // step 2 - keep track of number of child picked in `count` till now
    int count = 0;
    for(int i=0; i<k; i++){
        int hapVal = pq.top();
        pq.pop();

        // step 3 - calculate maximum possible happiness value
        res += max(0, hapVal - count);

        // increment count as we have picked on child
        count++;
    }

    // step 4 - return the maximum sum of the happiness values from `res`
    return res;
}

int main(){
    vector<int> happiness = {1,2,3};
    int k = 2;

    // vector<int> happiness = {1,1,1,1};
    // int k = 2;

    // vector<int> happiness = {2,3,4,5};
    // int k = 1;
    cout<<maximumHappinessSum(happiness, k);
    return 0;
}