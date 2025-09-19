
// Problem link - https://leetcode.com/problems/design-spreadsheet/description/?envType=daily-question&envId=2025-09-19

/**
 * @param {number} rows
 */
let Spreadsheet = function(rows) {
    // using 2D array as grid (rows x 26 columns for A-Z)
    this.sheet = Array(rows).fill().map(() => Array(26).fill(0));
};

/** 
 * @param {string} cell 
 * @param {number} value
 * @return {void}
 */
Spreadsheet.prototype.setCell = function(cell, value) {
    // find row and column from cell
    const col = cell.charCodeAt(0) - 'A'.charCodeAt(0);
    const row = parseInt(cell.substring(1)) - 1;
    
    // set the value
    this.sheet[row][col] = value;
};

/** 
 * @param {string} cell
 * @return {void}
 */
Spreadsheet.prototype.resetCell = function(cell) {
    // find row and column from cell
    const col = cell.charCodeAt(0) - 'A'.charCodeAt(0);
    const row = parseInt(cell.substring(1)) - 1;
    
    // reset the value
    this.sheet[row][col] = 0;
};

/**
 * Helper function to extract value from string (either number or cell reference)
 * @param {string} str
 * @return {number}
 */
Spreadsheet.prototype.extractValue = function(str) {
    // check if str is number
    if (/^\d/.test(str)) {
        // convert it into number and return
        return parseInt(str);
    }
    
    // otherwise find row and column from str
    const col = str.charCodeAt(0) - 'A'.charCodeAt(0);
    const row = parseInt(str.substring(1)) - 1;
    return this.sheet[row][col];
};

/** 
 * @param {string} formula
 * @return {number}
 */
Spreadsheet.prototype.getValue = function(formula) {
    // remove "=" from "=X+Y" expression
    const s = formula.substring(1);
    
    // find X and Y from "X+Y" expression
    const plusIndex = s.indexOf('+');
    const leftVal = s.substring(0, plusIndex);
    const rightVal = s.substring(plusIndex + 1);
    
    // evaluate X+Y and return the value
    return this.extractValue(leftVal) + this.extractValue(rightVal);
};

// test function
function main() {
    console.log("Testing Spreadsheet Implementation");
    console.log("==================================");
    
    // create a spreadsheet with 10 rows
    const spreadsheet = new Spreadsheet(10);
    
    // test setting cell values
    console.log("Setting values:");
    spreadsheet.setCell("A1", 5);
    spreadsheet.setCell("B1", 10);
    spreadsheet.setCell("C2", 15);
    console.log("A1 = 5, B1 = 10, C2 = 15");
    
    // test formulas with cell references
    console.log("\nTesting formulas:");
    const result1 = spreadsheet.getValue("=A1+B1");
    console.log("=A1+B1 =", result1); // Should be 15
    
    // test formulas with numbers
    const result2 = spreadsheet.getValue("=5+3");
    console.log("=5+3 =", result2); // Should be 8
    
    // test mixed formula (cell reference + number)
    const result3 = spreadsheet.getValue("=C2+5");
    console.log("=C2+5 =", result3); // Should be 20
    
    // test reset cell
    console.log("\nTesting reset:");
    console.log("Before reset - A1 value:", spreadsheet.sheet[0][0]); // Should be 5
    spreadsheet.resetCell("A1");
    console.log("After reset - A1 value:", spreadsheet.sheet[0][0]); // Should be 0
    
    const result4 = spreadsheet.getValue("=A1+B1");
    console.log("=A1+B1 after A1 reset =", result4); // Should be 10
    
    console.log("\nAll tests completed!");
}

// run the tests
main();