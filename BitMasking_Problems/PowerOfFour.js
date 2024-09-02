
// Problem link : https://leetcode.com/problems/power-of-four/

/*

# Approach :

1). n > 0: Ensures n is positive.
2). (n & (n - 1)) === 0: Checks if n is a power of two (only one bit set).
3). (n & 0xAAAAAAAA) === 0: Ensures the 1 bit is in an even position, confirming it's a power of four.

*/

let isPowerOfFour = function(n) {
    let exp1 = n > 0 && (n & (n-1)) === 0
    let exp2 = (n & 0xAAAAAAAA) === 0;
    return exp1 && exp2;
};

// let num = 16;

let num = 26;
console.log(isPowerOfFour(num));
