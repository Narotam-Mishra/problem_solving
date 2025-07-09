
// Problem link - https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/?envType=problem-list-v2&envId=array

let luckyNumbers = function(matrix) {
    const n = matrix.length;

    // store lucky numbers in `luckyNums`
    const luckyNums = [];

    // step 1 - loop through each row
    for(let i=0; i<n; i++){
        let row = matrix[i];
        let minVal = row[0];
        let minIndex = 0;

        // step 2 - check minimum element in current row
        for(let j=1; j<row.length; j++){
            if(row[j] < minVal){
                minVal = row[j];
                minIndex = j;
            }
        }

        // step 3 - check if this min value is also the maximum in its column
        let isMaxInCol = true;
        for(let k=0; k<n; k++){
            if(matrix[k][minIndex] > minVal){
                isMaxInCol = false;
                break;
            }
        }

        // step 4 - if it is the maximum in column, it's a lucky number
        if(isMaxInCol){
            luckyNums.push(minVal);
        }
    }

    // step 5 - return lucky number array `luckyNums`
    return luckyNums;
};

// const matrix = [[3,7,8],[9,11,13],[15,16,17]];

// const matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]];

const matrix = [[7,8],[1,2]];
console.log(luckyNumbers(matrix));