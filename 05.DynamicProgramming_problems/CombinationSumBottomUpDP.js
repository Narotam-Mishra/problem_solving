
// Problem link - https://leetcode.com/problems/combination-sum-iv/

let arr;
let dp;

function findNumberOfPossibleCombinationsBottomUpDP(target){
    dp = Array(target+1);

    for (let curTarget = 0; curTarget <= target; curTarget++) {
      // Base case: if target become 0 then we will first way
      if (curTarget === 0) dp[curTarget] = 1;
      // Recursive case: recurively calculate number of possible combinations that add up to target
      // f(target) = f(target - arr[i])
      else {
        let res = 0;
        for (let i = 0; i < arr.length; i++) {
          if (curTarget - arr[i] >= 0) {
            res += dp[curTarget - arr[i]];
          }
        }
        dp[curTarget] = res;
      }
    }
    return dp[target];
}

let combinationSum4 = function(nums, target) {
    arr = nums;
    return findNumberOfPossibleCombinationsBottomUpDP(target);
};

let nums = [1,2,3]; 
let target = 4
console.log(combinationSum4(nums, target));