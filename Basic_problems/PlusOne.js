
// Problem link - https://leetcode.com/problems/plus-one/

let plusOne1 = function(digits) {
     // Start from the end of the array (least significant digit)
     for(let i = digits.length-1; i >= 0; i--){
        // If the current digit is less than 9, we can simply increment it by one
        if(digits[i] < 9){
            digits[i]++;
            // No further carry, we can return the result
            return digits;
        }
        // If the current digit is 9, set it to 0 and continue to the next significant digit
        digits[i] = 0;
    }

    // If we have processed all digits and still have a carry, prepend 1 to the array
    digits.unshift(1);
    return digits;
};

let plusOne = function(digits) {
    // find size of digits
    let n = digits.length;

    // step 1 - iterate on digits from LSB and perform operation
    let i = n - 1;
    while(i >= 0) {
        // check if digit is less than 9
        if(digits[i] < 9) {
            // simply increment by 1
            digits[i] += 1;
            return digits;
        }

        // check if digit is 9 than, add carry
        digits[i] = 0;
        i--;
    }

    // step 2 - corner case
    // if we have processed all digits and still have a carry, add that carry in start
    digits.unshift(1);

    // step 3 - return final result from digits
    return digits;
}

// Example usage:
let digits = [1, 2, 3];
console.log(plusOne(digits)); // Output: [1, 2, 4]

digits = [9, 9, 9];
console.log(plusOne(digits)); // Output: [1, 0, 0, 0]