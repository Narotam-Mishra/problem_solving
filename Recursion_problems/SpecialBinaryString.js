
// Problem link - https://leetcode.com/problems/special-binary-string/description/

// recursive function to make special string lexicographically largest
function solveRec(s) {

    // array to store top-level special substrings
    const specialStrs = [];

    let sum = 0;      // balance counter
    let start = 0;    // start index of current special substring

    // step 1 - traverse string to split into maximum top-level special substrings
    for (let i = 0; i < s.length; i++) {

        // update balance
        sum += (s[i] === '1') ? 1 : -1;

        // step 2 - if balance becomes 0, we found one complete special substring
        if (sum === 0) {

            // extract inner substring (excluding outer 1 and 0)
            const inner = s.substring(start + 1, i);

            // step 3 - recursively process inner substring
            const processed = "1" + solveRec(inner) + "0";

            specialStrs.push(processed);

            // move start pointer
            start = i + 1;
        }
    }

    // step 4 - sort in descending lexicographical order
    specialStrs.sort((a, b) => b.localeCompare(a));

    // step 5 - concatenate sorted substrings
    return specialStrs.join("");
}

// Main function
let makeLargestSpecial = function(s) {
    return solveRec(s);
}

// const s = "11011000";

const s = "10";
console.log(makeLargestSpecial(s));