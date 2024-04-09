
// Problem link - https://leetcode.com/problems/arithmetic-slices-ii-subsequence/

// Approach - using Bottom Up DP

let arr;
let dp;

function findNumOfArithmeticSlicesIIBottomUpDP(){
    let size = arr.length;

    // dp --> array of objects (map) to store key value configurations
    dp = Array(size);
    for(let i=0; i<size; i++){
        dp[i] = {};
    }

    let ans = 0;
    for(let i=1; i<size; i++){
        for(let j=0; j<i; j++){
            // calculate common difference diff
            let diff = arr[i] - arr[j];
            // Check whether the map of index 'j' has difference 'diff' as the key
            if(dp[j][diff]){
                // Increment the answer by the number of arithmetic slices found
                ans += dp[j][diff];
                if(dp[i][diff]){
                    // Update the count of slices for index 'i' and difference 'diff'
                    dp[i][diff] += 1 + dp[j][diff]
                }else{
                    // Initialize the count of slices for index 'i' and difference 'diff'
                    dp[i][diff] = 1 + dp[j][diff]
                }
            }else{
                if(dp[i][diff]){
                    dp[i][diff] += 1;
                }else{
                    dp[i][diff] = 1;
                }
            }
        }
    }
    // Return the total number of arithmetic slices found
    return ans;
}

let numberOfArithmeticSlices = function(nums) {
    arr = nums;
    return findNumOfArithmeticSlicesIIBottomUpDP();
};

// let nums = [2,4,6,8,10];
nums = [7,7,7,7,7]
console.log(numberOfArithmeticSlices(nums));