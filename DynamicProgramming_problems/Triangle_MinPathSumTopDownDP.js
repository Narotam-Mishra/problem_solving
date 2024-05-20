
// Problem link - https://leetcode.com/problems/triangle/

let matrix;
let dp;

function findMinimumPathSumTopDownDP(row, col){
    // base case: if row is last row then return current element
    if(row === matrix.length - 1){
        return matrix[row][col];
    }

    // if dp[row][col] is already calculated then return dp[row][col]
    if(dp[row][col] !== -1) return dp[row][col];

    // Recursive Case : recursively calculate the minimum path sum
    return dp[row][col] = matrix[row][col] + Math.min(findMinimumPathSumTopDownDP(row+1, col), findMinimumPathSumTopDownDP(row+1, col+1));
}

let minimumTotal = function(triangle) {
    matrix = triangle;
    dp = Array(matrix.length).fill().map(() => new Array(matrix.length).fill(-1));
    return findMinimumPathSumTopDownDP(0,0);
};

let triangle = [[2],[3,4],[6,5,7],[4,1,8,3]];
let ans = minimumTotal(triangle);
console.log(ans);
