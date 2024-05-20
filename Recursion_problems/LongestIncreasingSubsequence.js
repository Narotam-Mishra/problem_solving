
// Problem link - https://leetcode.com/problems/longest-increasing-subsequence/description/

let arr;

function LIS_Rec(i){
    // Base case: if ith index 'i' is at 0
    if(i === 0) return 1;

    // there will be atleast 1 increasing subsequence in array always
    let res = 1;

    for(let j=0; j<=i-1; j++){
        if(arr[j] < arr[i]){
            res = Math.max(res, 1 + LIS_Rec(j));
        }
    }
    return res;
}

let lengthOfLIS = function(nums) {
    arr = nums;
    let ans = Number.MIN_VALUE;
    
    for(let i=0; i<arr.length; i++){
        ans = Math.max(ans, LIS_Rec(i));
    }
    return ans;
};

// let nums = [0,1,0,3,2,3];

// let nums = [10,9,2,5,3,7,101,18]

// let nums = [7,7,7,7,7,7,7];

let nums = [1,3,6,7,9,4,10,5,6]
console.log(lengthOfLIS(nums));