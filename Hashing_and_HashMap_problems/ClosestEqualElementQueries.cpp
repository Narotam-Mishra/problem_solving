
// Problem link - https://leetcode.com/problems/closest-equal-element-queries/description/?envType=daily-question&envId=2026-04-16

#include<bits/stdc++.h>
using namespace std;

vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
    int n = nums.size();

    // step 1 - find occurence of element in map
    unordered_map<int, vector<int>> mp;
    for(int i=0; i<n; i++){
        mp[nums[i]].push_back(i);
    }

    // step 2 - iterate and solve each query 
    vector<int> result;
    for(int qi : queries){
        int element = nums[qi];
        vector<int>& occList = mp[element];

        int len = occList.size();
        if(len == 1){
            result.push_back(-1);
            continue;
        }

        // step 3 - using lower bound to find qi in occList
        int qiPos = lower_bound(begin(occList), end(occList), qi) - begin(occList);

        // step 4 - calculate minimum distance for left and right neighbour
        // keep track of minimum distance
        int res = INT_MAX;

        // find right neighbour, distance & circular distance
        int right = occList[(qiPos + 1) % len];
        int dist = abs(qi - right);
        int cirDist = n - dist;

        // update minimum distance for right
        res = min({res, dist, cirDist});

        // find left neighbour, distance & circular distance
        int left = occList[(qiPos - 1 + len) % len];
        dist = abs(qi - left);
        cirDist = n - dist;

        // update minimum distance for left
        res = min({res, dist, cirDist});

        // store res in final result
        result.push_back(res);
    }

    // step 5 - return final resultant list
    return result;
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
    // vector<int> nums = {1,3,1,4,1,3,2};
    // vector<int> queries = {0,3,5};

    vector<int> nums = {1,2,3,4};
    vector<int> queries = {0,1,2,3};
    vector<int> res = solveQueries(nums, queries);
    printVector(res);
    return 0;
}