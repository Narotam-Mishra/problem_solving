
// Problem link : https://leetcode.com/problems/excel-sheet-column-title/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

let convertToTitle = function(columnNumber) {
    let title = '';

    while(columnNumber > 0){
        // decrement columnNumber by 1 to handle 1-based indexing 
        // for 'A' -> 1, 'B' -> 2, ..., 'Z' -> 26
        columnNumber--;

        // find the current letter to prepend to the title
        // ASCII value of 'A' is 65, so to map 0 -> 'A', 1 -> 'B', ..., 25 -> 'Z'
        // we add 65 to get the correct character code
        let letter = String.fromCharCode((columnNumber % 26) + 65);

        // prepend the letter to the result string
        title = letter + title;

        // move to the next position by dividing by 26
        columnNumber = Math.floor(columnNumber / 26);
    }
    return title;
};

// let columnNumber = 1;

// let columnNumber = 26;

// let columnNumber = 27;

let columnNumber = 28;
console.log(convertToTitle(columnNumber));
