
// Problem link - https://leetcode.com/problems/maximum-matrix-sum/description/?envType=daily-question&envId=2026-01-05

let maxMatrixSum = function(matrix) {
    let n = matrix.length;

    // step 1 - find overall absolute sum of matrix's values
    let totalSum = 0;
    let negativesCount = 0;
    let minAbsVal = Infinity;
    for(let i=0; i<n; i++){
        for(let j=0; j<n; j++){
            // step 2 - count negative numbers
            if(matrix[i][j] < 0){
                negativesCount++;
            }

            // keep track of minimum absolute value in matrix
            minAbsVal = Math.min(minAbsVal, Math.abs(matrix[i][j]));
            
            // calculate overall running sum of absolute values
            totalSum += Math.abs(matrix[i][j]);
        }
    }

    // step 3 - check if count of negatives is even or not
    if(negativesCount % 2 == 0){
        // return overall sum in case of even negatives count
        return totalSum;
    }

    // step 4 - if odd negatives, we must flip one negative number to positive
    // subtract 2*minAbsVal because: once to remove it from sum, once to flip its sign
    return totalSum - 2 * minAbsVal;
};

// const matrix = [[1,-1],[-1,1]];

const matrix = [[1,2,3],[-1,-2,-3],[1,2,3]];
console.log(maxMatrixSum(matrix));