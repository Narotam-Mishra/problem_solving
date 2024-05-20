
// Problem link - https://leetcode.com/problems/combination-sum-iv/

#include<bits/stdc++.h>
using namespace std;

vector<int> arr;

int findNumberOfPossibleCombinationsRec(int curTarget){
    // Base case: if target become 0 then we will first way
    if (curTarget == 0)
        return 1;

    // Recursive case: recurively calculate number of possible combinations that add up to target
    // f(target) = f(target - arr[i])

    int res = 0;
    for (int i = 0; i < arr.size(); i++){
        if (curTarget - arr[i] >= 0){
            res += findNumberOfPossibleCombinationsRec(curTarget - arr[i]);
        }
    }
    return res;
}

int combinationSum4(vector<int>& nums, int target) {
    arr = nums;
    return findNumberOfPossibleCombinationsRec(target);
}

int main(){
    vector<int> nums = {1,2,3};
    int target = 4;
    cout<<combinationSum4(nums, target)<<endl;
    return 0;
}