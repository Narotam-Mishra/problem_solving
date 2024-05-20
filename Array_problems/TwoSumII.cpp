
// Problem link - https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int s = 0;
        int e = numbers.size()-1;

        while(s<e){
            if(numbers[s] + numbers[e] == target){
                return {s+1, e+1};
            }else if(numbers[s] + numbers[e] > target){
                e--;
            }else{
                s++;
            }
        }
        return {};
    }
};