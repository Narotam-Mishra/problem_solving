
// Problem link - https://leetcode.com/problems/number-of-lines-to-write-string/description/

let numberOfLines = function(widths, s) {
    // step 1 - start with first line
    // initialize current width
    let lines = 1, currentWidth = 0;
    const maxWidth = 100;

    // step 2 - iterate on each character of string `s`
    for(let ch of s){
        // step 3 - find corresponding width of current character
        let charWidth = widths[ch.charCodeAt(0) - 'a'.charCodeAt(0)];

        // step 4 - check if adding this character would exceed the line limit
        if(charWidth + currentWidth > maxWidth){
            // start new line
            lines++;
            currentWidth = charWidth;
        }else{
            // otherwise add character to current line
            currentWidth += charWidth;
        }
    }

    // step 5 - return [total number of lines, width of the last line]
    return [lines, currentWidth];
};

// const widths = [10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10], s = "abcdefghijklmnopqrstuvwxyz";

const widths = [4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10], s = "bbbcccdddaaa";
console.log(numberOfLines(widths, s));