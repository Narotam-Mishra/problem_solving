
// Problem link - https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/?envType=daily-question&envId=2026-03-04

let numSpecial = function(mat) {
    // find row and column size
    let m = mat.length;
    let n = mat[0].length;

    // keep track row and column ones
    const rowOne = new Array(m).fill(0);
    const colOne = new Array(n).fill(0);

    // step 1 - iterate on matrix & count 1s
    for(let i=0; i<m; i++){
        for(let j=0; j<n; j++){
            if(mat[i][j] == 1){
                rowOne[i]++;
                colOne[j]++;
            }
        }
    }

    // step 2 - find special posiiton
    let specialCount = 0;
    for(let i=0; i<m; i++){
        for(let j=0; j<n; j++){
            if(mat[i][j] == 1 && rowOne[i] == 1 && colOne[j] == 1){
                specialCount++;
            }
        }
    }

    // step 3 - return special count
    return specialCount;
};

const mat = [[1,0,0],[0,0,1],[1,0,0]];
console.log(numSpecial(mat));