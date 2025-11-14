
// Problem link - https://leetcode.com/problems/increment-submatrices-by-one/description/?envType=daily-question&envId=2025-11-14

let rangeAddQueries = function(n, queries) {
    // step 1 - create an n x n matrix initialized with 0s
    const mat = Array.from({ length: n}, () => Array(n).fill(0));

    // step 2 - process each query
    for(const query of queries){
        let row1 = query[0];
        let col1 = query[1];
        let row2 = query[2];
        let col2 = query[3];

        // step 2 - populate DAT
        for(let r=row1; r<=row2; r++){
            mat[r][col1] += 1;

            if(col2 + 1 < n){
                mat[r][col2 + 1] -= 1;
            }
        }
    }

    // step 3 - find cummulative sum of `mat`
    for(let i=0; i<n; i++){
        for(let j=1; j<n; j++){
            mat[i][j] += mat[i][j-1];
        }
    }

    // step 4 - return final result from `mat`
    return mat;
};

// const n = 3, queries = [[1,1,2,2],[0,0,1,1]];

const n = 2, queries = [[0,0,1,1]];
console.log(rangeAddQueries(n, queries));