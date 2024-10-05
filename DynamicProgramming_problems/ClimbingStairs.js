
// Problem link : https://leetcode.com/problems/climbing-stairs/

let memo = {};
function helper(n){
    // base case:
    if(n === 1 || n === 2) return n;

    // if value is already computed then return
    if(memo[n]) return memo[n];

    // recursively calculate and store result into memo
    memo[n] = helper(n - 1) + helper(n - 2);
    return memo[n];

}
let climbStairs = function(n) {
    return helper(n);
};

// let n = 3;

let n = 5;
console.log(climbStairs(n));
