
// Problem link - https://leetcode.com/problems/delete-greatest-value-in-each-row/description/?envType=problem-list-v2&envId=array

let deleteGreatestValue = function(grid) {
    // step 1 - sort each row in descending order
    for(let i=0; i<grid.length; i++){
        grid[i].sort((a,b) => b - a);
    }

    // step 2 - process each column
    let ans = 0;
    for (let j = 0; j < grid[0].length; j++) {
        let maxNum = 0;

        // step 3 - find maximum among all rows for this column
        for(let i=0; i<grid.length; i++){
            maxNum = Math.max(maxNum, grid[i][j]);
        }

        // step 4 - add the maximum of deleted elements to the answer
        ans += maxNum;
    }

    // step 5 - return answer, `ans`
    return ans;
};

// const grid = [[1,2,4],[3,3,1]];

const grid = [[10]];
console.log(deleteGreatestValue(grid));