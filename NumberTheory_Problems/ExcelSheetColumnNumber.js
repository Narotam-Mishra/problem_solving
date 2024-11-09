
// Problem link : https://leetcode.com/problems/excel-sheet-column-number/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

let titleToNumber = function(columnTitle) {
    // intialize columnNumber to 0 and store actual result in it, 
    let columnNumber = 0;

    // iterate on each character of column title
    for(let i=0; i<columnTitle.length; i++) {
        // shift columnNumber up by 26 for the new place
        columnNumber *= 26;

        // add the value of the current character (A=1, B=2, ..., Z=26)
        columnNumber += columnTitle.charCodeAt(i) - 'A'.charCodeAt(0) + 1;
    }

    // return actual result
    return columnNumber;
};

// let columnTitle = "A";

// let columnTitle = "AB";

let columnTitle = "ZY";
console.log(titleToNumber(columnTitle));
