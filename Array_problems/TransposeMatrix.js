
// Problem link - https://leetcode.com/problems/transpose-matrix/description/?envType=problem-list-v2&envId=array

let transpose = function(matrix) {
    // find row and column length of matrix in `m` & `n`
    const m = matrix.length;
    const n = matrix[0].length;

    // step 1 - store result in `res` matrix
    const res = Array.from({ length : n}, () => Array(m));

    // step 2 - iterate on matrix 
    for(let i=0; i<m; i++){
        for(let j=0; j<n; j++){
            // step 3 - find transpose matrix, i.e, matrix[i][j] = matrix[j][i] 
            res[j][i] = matrix[i][j];
        }
    }

    // step 4 - return  resultant tranposed matrix `res`
    return res;
};

// const matrix = [[1,2,3],[4,5,6],[7,8,9]];

const matrix = [[1,2,3],[4,5,6]];
console.log(transpose(matrix));