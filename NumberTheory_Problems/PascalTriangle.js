
// Problem link : https://leetcode.com/problems/pascals-triangle/description/

let generate = function(numRows) {
    let res = [];
    for(let i=0; i<numRows; i++){
        let row = [1];
        for(let j=1; j<=i; j++){
            row.push(row[j-1] * (i-j+1)/j);
        }
        res.push(row);
    }
    return res;
};

// let numRows = 5;

let numRows = 1;
console.log(generate(numRows));
