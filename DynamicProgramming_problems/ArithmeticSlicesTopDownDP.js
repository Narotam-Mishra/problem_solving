
// Problem link - https://leetcode.com/problems/arithmetic-slices/description/

// Approach - using TopDown DP

let arr;
let dp;

function findNumOfArithmeticSlicesTopDownDP(i){
    // Base case1: if ith index is 0 or 1 then there is no Arithmetic slice return 0
    if(i === 0 || i === 1) return dp[i] = 0;

    // Base case2 : if the difference between any two consecutive elements is not the same then return 0
    else if(arr[i] - arr[i-1] !== arr[i-1] - arr[i-2]) return dp[i] = 0;

    // if dp[i] is already calculated then return dp[i]
    if(dp[i] !== -1) return dp[i];

    else{
        // Recursive case:
        return dp[i] = 1 + findNumOfArithmeticSlicesTopDownDP(i-1);
    }
}

function findNumOfArithmeticSlicesBottomUpDP(){
    for (let i = 0; i < arr.length; i++) {
        // Base case1: if ith index is 0 or 1 then there is no Arithmetic slice return 0
        if (i === 0 || i === 1) dp[i] = 0;

        // Base case2 : if the difference between any two consecutive elements is not
        // the same then return 0
        else if (arr[i] - arr[i - 1] != arr[i - 1] - arr[i - 2]) dp[i] = 0;

        else {
            // store ans in Bottom Up DP
            dp[i] = 1 + dp[i - 1];
        }
    }

    let res = 0;
    for(let id=0; id<arr.length; id++){
        res += dp[id];
    }

    return res;
}

let numberOfArithmeticSlices = function(nums) {
    let size = nums.length;
    arr = nums;
    dp = Array(size+1);
    return findNumOfArithmeticSlicesBottomUpDP();
};

let numberOfArithmeticSlices1 = function(nums) {
    let size = nums.length;
    arr = nums;
    dp = Array(size+1).fill(-1);
    let ans = 0;
    for(let i=0; i<size; i++){
        ans += findNumOfArithmeticSlicesTopDownDP(i);
    }
    return ans;
};

let nums = [1,2,3,4];
console.log(numberOfArithmeticSlices(nums));