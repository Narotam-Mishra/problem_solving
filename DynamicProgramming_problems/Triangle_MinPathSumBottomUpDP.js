
// Problem link - https://leetcode.com/problems/triangle/

let matrix;
let dp;

function findMinimumPathSumBottomUpDP(){
    // intialize 2-D DP array
    dp = Array(matrix.length);
    for(let i=0; i<matrix.length; i++){
        dp[i] = Array(matrix.length);
    }

    let totalRow = matrix.length;
    // Base case:
    for(let i=0; i<matrix[totalRow-1].length; i++){
        dp[totalRow-1][i] = matrix[totalRow-1][i];
    }

    // fill the 2-D DP in bottom up manner
    for(let row = totalRow-2; row>=0; row--){
        for(let col=0; col < matrix[row].length; col++){
            dp[row][col] = matrix[row][col] + Math.min(dp[row+1][col], dp[row+1][col+1]);
        }
    }

    return dp[0][0];
}

let minimumTotal = function(triangle) {
    matrix = triangle;
    return findMinimumPathSumBottomUpDP();
};

let triangle = [[2],[3,4],[6,5,7],[4,1,8,3]];
let ans = minimumTotal(triangle);
console.log(ans);
