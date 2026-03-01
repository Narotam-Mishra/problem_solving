
// Problem link - https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/description/?envType=daily-question&envId=2026-03-01

let minPartitions = function(n) {
    // keep track of  maximum digit in `n`
    let maxDigit = 0;

    // step 1 - traverse each character
    for (let ch of n) {

        // step 2 - convert character to number
        let digit = ch - '0';

        // step 3 - update maximum digit
        maxDigit = Math.max(maxDigit, digit);
    }

    // step 4 - return maximum digit
    return maxDigit;
};

// const n = "32";

// const n = "27346209830709182346";

const n = "82734";
console.log(minPartitions(n));