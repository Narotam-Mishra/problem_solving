
// Problem link : https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/description/?envType=problem-list-v2&envId=hash-table

#include<bits/stdc++.h>
using namespace std;

vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    // step 1 - create an array of pairs (value, index)
    vector<pair<int, int>> pairs;
    for(int i=0; i<nums.size(); i++){
        pairs.push_back({nums[i], i});
    }

    // step 2 - sort the array by value
    sort(pairs.begin(), pairs.end());

    // step 3 - create a map to store the count of smaller numbers
    unordered_map<int, int> map;

    // step 4 - iterate through the sorted array and assign counts based on the index
    for(int i=0; i<pairs.size(); i++) {
        // only assign if the number hasn't been assigned yet (to handle duplicates)
        if(map.find(pairs[i].first) == map.end()){
            map[pairs[i].first] = i;
        }
    }

    // step 5 - build the result array `res` and return `res`
    vector<int> res(nums.size());
    for(int i=0; i<nums.size(); i++) {
        res[i] = map[nums[i]];
    }
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
    // vector<int> nums = {8,1,2,2,3};

    // vector<int> nums = {6,5,4,8};

    vector<int> nums = {0,0,0,0};
    vector<int> res = smallerNumbersThanCurrent(nums);
    printVector(res);
    return 0;
}