
// Problem link - https://leetcode.com/problems/search-a-2d-matrix-ii/description/?envType=problem-list-v2&envId=array

let searchMatrix = function(matrix, target) {
    // step 1 - initialize starting position at the top-right corner
    let row = 0;
    let col = matrix[0].length - 1;

    // step 2 - traverse the matrix
    while(row < matrix.length && col >= 0){
        // step 3 - get current element
        let current = matrix[row][col];

        // step 4 - check if current element is target
        if(target === current){
            return true;
        }

        // step 5 - if current element is greater than target than, move left
        else if(current > target){
            col--;
        }

        // step 6 - if current element is smaller than target, move down
        else{
            row++;
        }
    }

    // step 7 - return false if target not found
    return false;
};

// const matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5;

const matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20;
console.log(searchMatrix(matrix, target));
