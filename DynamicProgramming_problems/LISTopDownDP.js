
// Problem link - https://leetcode.com/problems/longest-increasing-subsequence/description/

let arr;
let dp;

function LIS_BottomUpDP() {
  dp = Array(2700);

  for (let i = 0; i < arr.length; i++) {
    // Base case: if ith index 'i' is at 0
    if (i == 0) dp[i] = 1;

    else {
      // there will be atleast 1 increasing subsequence in array always
      let res = 1;

      for (let j = 0; j <= i - 1; j++) {
        if (arr[j] < arr[i]) {
          res = Math.max(res, 1 + dp[j]);
        }
      }
      dp[i] = res;
    }
  }

  // calculate final ans
  let ans = Number.MIN_VALUE;
  for (let i = 0; i < arr.length; i++) {
    ans = Math.max(ans, dp[i]);
  }
  return ans;
}

let lengthOfLIS = function(nums) {
    arr = nums;
    return LIS_BottomUpDP();
};

function LIS_TopDownDP(i){
    // Base case: if ith index 'i' is at 0
    if(i === 0) return 1;

    // if dp[i] is already calculated then return dp[i];
    if(dp[i] !== -1) return dp[i];

    // there will be atleast 1 increasing subsequence in array always
    let res = 1;

    for(let j=0; j<=i-1; j++){
        if(arr[j] < arr[i]){
            res = Math.max(res, 1 + LIS_TopDownDP(j));
        }
    }
    dp[i] = res;
    return res;
}

let lengthOfLIS1 = function(nums) {
    arr = nums;
    dp = Array(nums.length+1).fill(-1);
    let ans = Number.MIN_VALUE;
    
    for(let i=0; i<arr.length; i++){
        ans = Math.max(ans, LIS_TopDownDP(i));
    }
    return ans;
};

// let nums = [0,1,0,3,2,3];

// let nums = [10,9,2,5,3,7,101,18]

// let nums = [7,7,7,7,7,7,7];

let nums = [1,3,6,7,9,4,10,5,6]
console.log(lengthOfLIS(nums));