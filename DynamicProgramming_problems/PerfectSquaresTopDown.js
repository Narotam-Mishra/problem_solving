

// Problem link - https://leetcode.com/problems/perfect-squares/description/

// Approach - Top Down DP

let sqArr;
let dp;

function PerfectSquaresTopDownDP(num){
    // Base case: if num is 0 return 0
    if(num === 0) return 0;

    // if dp[num] is already calculated then return its value
    if(dp[num] !== -1) return dp[num];

    let ans = Number.MAX_VALUE;
    let n = sqArr.length;

    // Recursive case f(num) = 1 + min(f(num - sqArr[i]))
    for(let i=0; i<n; i++){
        if(num >= sqArr[i]){
            ans = Math.min(ans, PerfectSquaresTopDownDP(num - sqArr[i]));
        }
    }

    return dp[num] = 1 + ans;
}

let numSquares = function(n) {
    sqArr = Array(100);
    let j = 0;

    for(let i=1; i*i<=10000; i++){
        sqArr[j] = i * i;
        j++;
    }

    dp = Array(n+1).fill(-1);
    let res = PerfectSquaresTopDownDP(n);
    return res;
};

// let n = 12;

let n = 13;
let res = numSquares(n);
console.log(res);
