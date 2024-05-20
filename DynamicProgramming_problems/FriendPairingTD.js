
// Problem link - https://www.codingninjas.com/studio/problems/friends-pairing-problem_1214625?leftPanelTabValue=PROBLEM

// Approach - Top Down DP (Memoization)

let dp;
let mod = 1000000007;

function friendPairing(n){
    if(n === 1 || n === 2) return n;

    // if dp[n] is already calculated then return dp[n]
    if(dp[n] !== -1) return dp[n];

    let singleWay = friendPairing(n-1) % mod;
    let pairedWay = ((n-1) % mod * friendPairing(n-2) % mod) % mod;

    return dp[n] = (singleWay + pairedWay)%mod;
}

function numberOfWays(n){
    dp = Array(n+1).fill(-1);
    return friendPairing(n);
}

let n = 1000;
console.log(numberOfWays(n));