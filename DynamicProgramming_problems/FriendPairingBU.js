
// Problem link - https://www.codingninjas.com/studio/problems/friends-pairing-problem_1214625?leftPanelTabValue=PROBLEM

// Approach - Top Down BU (Tabulation)

function friendPairing(n){
    const mod = 1000000007;
    let dp = new Array(n + 1).fill(0);

    if(n === 1 || n === 2) return n;

    dp[1] = 1;
    dp[2] = 2;

    for(let i = 3; i <= n; i++){
        dp[i] = (dp[i-1] + ((i-1) * dp[i-2]) % mod) % mod;
    }

    return dp[n];
}

function numberOfWays(n){
    return friendPairing(n);
}

// Example usage:
let n = 32415;
console.log(numberOfWays(n));
