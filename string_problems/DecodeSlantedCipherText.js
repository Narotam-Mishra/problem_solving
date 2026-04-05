
// problem link - https://leetcode.com/problems/decode-the-slanted-ciphertext/description/

let decodeCiphertext = function(encodedText, rows) {
    let len = encodedText.length;

    // step 1 - find number of column
    let col = Math.floor(len / rows);

    // step 2 - iterate on encoded string diagonally
    let originalText = "";

    for (let c = 0; c < col; c++) {
        for (let j = c; j < len; j += (col + 1)) {
            // step 3 - prepare original string
            originalText += encodedText[j];
        }
    }

    // step 4 - remove trailing spaces
    while (originalText.length > 0 && originalText[originalText.length - 1] === ' ') {
        originalText = originalText.slice(0, -1);
    }

    // step 5 - return result
    return originalText;
};