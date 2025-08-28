
// Problem link - https://leetcode.com/problems/sort-matrix-by-diagonals/description/?envType=daily-question&envId=2025-08-28

let sortMatrix = function(grid) {
    // find size of grid
    const n = grid.length;

    // helper function to process digonal elements
    function processDiagonal(si, sj){
        const vals = [];
        let i = si, j = sj;

        // collect values along this diagonal
        while(i < n && j < n){
            vals.push(grid[i][j]);
            i++; 
            j++;
        }

        // decide sorting order based on diagonal key diff = si - sj
        const diff = si - sj;
        if(diff >= 0){
            // bottom-left & main diagonal --> descending order sorting
            vals.sort((a,b) => b - a);
        }else{
            // top right --> ascending order sorting
            vals.sort((a,b) => a - b);
        }

        // write sorted values back along diagonal
        i = si, j = sj;
        let index = 0;
        while(i < n && j < n){
            grid[i][j] = vals[index++];
            i++;
            j++;
        }
    }

    // step 1 - start diagonals from top row (0, c)
    for(let c=0; c<n; c++){
        // step 2 - process digonal along top right
        processDiagonal(0, c);
    }

    // step 3 - start diagonal from the first column (r, 0)
    // skipping row 0 to avoid repeating main diagonal
    for(let r=1; r<n; r++){
        // step 4 - process digonal along bottom-left
        processDiagonal(r, 0);
    }

    // step 5 - return final diagonal sorted grid
    return grid;
};

const grid = [[1,7,3],[9,8,2],[4,5,6]];
console.log(sortMatrix(grid));