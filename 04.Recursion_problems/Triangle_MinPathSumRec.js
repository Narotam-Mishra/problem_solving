
// Problem link - https://leetcode.com/problems/triangle/

let matrix;

function findMinimumPathSumRecursive(row, col){
    // base case: if row is last row then return current element
    if(row === matrix.length - 1){
        return matrix[row][col];
    }

    // Recursive Case : recursively calculate the minimum path sum
    return matrix[row][col] + Math.min(findMinimumPathSumRecursive(row+1, col), findMinimumPathSumRecursive(row+1, col+1));
}

let minimumTotal = function(triangle) {
    matrix = triangle;
    return findMinimumPathSumRecursive(0,0);
};

let triangle = [[2],[3,4],[6,5,7],[4,1,8,3]];
let ans = minimumTotal(triangle);
console.log(ans);
