
// Problem link - https://leetcode.com/problems/diagonal-traverse/description/?envType=daily-question&envId=2025-08-25

let findDiagonalOrder = function(mat) {
    // find row and column size of matrix
    const m = mat.length;
    const n = mat[0].length;

    // store result in `res`
    const res = [];

    // step 1 - traverse each element digonal sum wise
    for(let ds=0; ds<m+n-1; ds++){
        let currDiagonal = [];

        // step 2 - find all element in current diagonal where `i + j = diagonal sum (ds)`
        for(let i=0; i<m; i++){
            // calculate column index
            let j = ds - i;

            // step 3 - check calculated column index is valid 
            if(j >= 0 && j<n){
                currDiagonal.push(mat[i][j]);
            }
        }

        // step 4 - alernate the direction of traversal for each diagonal
        // odd diagonals (1, 3, 5...): traverse top-right to bottom-left
        // even diagonals (2, 4, 6...): traverse bottom-left to top-right
        if(ds % 2 === 0){
            currDiagonal.reverse();
        }

        // step 5 - add diagonal elements to result `res`
        res.push(...currDiagonal);
    }

    // step 6 - return result `rs`
    return res;
};

// const mat = [[1,2,3],[4,5,6],[7,8,9]];

const mat = [[1,2],[3,4]];
console.log(findDiagonalOrder(mat));