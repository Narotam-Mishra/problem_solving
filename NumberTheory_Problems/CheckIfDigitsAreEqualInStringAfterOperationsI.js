
// Problem link - https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/description/?envType=problem-list-v2&envId=number-theory

let hasSameDigits = function(s) {
    // step 1 - convert the string into an array of digits
    let digits = s.split('').map(Number);

    // compute digits length
    let n = digits.length;

    // step 2 - keep reducing the array until only two digits remain
    while(n > 2){
        // step 3 - compute new digits based on adjacent pairs
        for(let i=0; i<digits.length - 1; i++){
            digits[i] = (digits[i] + digits[i+1]) % 10;
        }

        // step 4 - reduce the effective length of the array
        n--;
    }

    // step 5 - check if final two gits are equal or not
    return digits[0] === digits[1];
};

const s = "3902";

// const s = "34789";
console.log(hasSameDigits(s));
