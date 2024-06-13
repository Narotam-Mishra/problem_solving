
// Problem link - https://leetcode.com/problems/plus-one/

let plusOne = function(digits) {
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

// Example usage:
let digits = [1, 2, 3];
console.log(plusOne(digits)); // Output: [1, 2, 4]

digits = [9, 9, 9];
console.log(plusOne(digits)); // Output: [1, 0, 0, 0]