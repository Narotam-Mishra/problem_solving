
// Problem link - https://leetcode.com/problems/reshape-the-matrix/?envType=problem-list-v2&envId=array

// Approach - 1 (Brute Force)
let matrixReshape1 = function(mat, r, c) {
    // find row and column size of input matrix `mat`
    const m = mat.length;
    const n = mat[0].length;

    // step 1 - check for edge case : check if reshap is possible or not
    if(m * n !== r * c){
        // if reshape is not possible then return original input matrix `mat`
        return mat;
    }

    // step 2 - flatten the original input 2-D array `mat` into 1-D array `flatten`
    // this is done to maintain original array order
    const flatten = []
    for(let i=0; i<m; i++){
        for(let j=0; j<n; j++){
            flatten.push(mat[i][j]);
        }
    }

    // store final result in reshaped matrix `reshape`
    const reshape = [];
    
    // keep track of index
    let index = 0;

    // step 3 - fill the new matrix row by row using flattened data
    for(let i=0; i<r; i++){
        // create new array
        const row = [];
        for(let j=0; j<c; j++){
            // add element to current row
            row.push(flatten[index]);
            // move to next element in flatten array
            index++;
        }

        // add completed row to reshaped matrix
        reshape.push(row);
    }

    // step 4 - return reshaped matrix `reshaped`
    return reshape;
};

// Approach2 - Optimal
let matrixReshape = function(mat, r, c) {
    // find row and column size of input matrix `mat`
    const m = mat.length;
    const n = mat[0].length;

    // step 1 - check for edge case : if total element differ then reshap is not possible
    if(m * n != r * c){
        return mat;
    }

    // store final result in `reshaped` matrix
    const reshaped = Array.from({ length: r }, () => Array(c).fill(0));

    // step 2 - fill the new `reshaped` matrix 
    // single linear pass over all elements (row-major order)
    for(let k=0; k<m*n; k++){
        // step 3 - calculate original position in matrix `mat`
        let originalRow = Math.floor(k / n);
        let originalColumn = k % n;

        // step 4 - find new position in reshaped matrix
        let newRow = Math.floor(k / c);
        let newColumn = k % c;

        // move the element
        reshaped[newRow][newColumn] = mat[originalRow][originalColumn];
    } 
        
    // step 5 - return reshaped matrix `reshaped`
    return reshaped;
};

const mat = [[1,2],[3,4]], r = 1, c = 4;

// const mat = [[1,2],[3,4]], r = 2, c = 4;
console.log(matrixReshape(mat, r, c));