
// Problem link - https://leetcode.com/problems/combination-sum-iv/

let arr;
let dp;

function findNumberOfPossibleCombinationsTopDownDP(curTarget){
    // Base case: if target become 0 then we will first way
    if(curTarget === 0) return 1;
    
    // if dp[target] is already calculated then return dp[target]
    if(dp[curTarget] != -1){
        return dp[curTarget];
    }

    // Recursive case: recurively calculate number of possible combinations that add up to target
    // f(target) = f(target - arr[i])

    let res = 0;
    for(let i=0; i<arr.length; i++){
        if(curTarget - arr[i] >= 0){
            res += findNumberOfPossibleCombinationsTopDownDP(curTarget - arr[i]);
        }
    }
    dp[curTarget] = res;
    return res;
}

let combinationSum4 = function(nums, target) {
    arr = nums;
    dp = Array(target + 1).fill(-1);
    return findNumberOfPossibleCombinationsTopDownDP(target);
};

let nums = [1,2,3]; 
let target = 4
console.log(combinationSum4(nums, target));