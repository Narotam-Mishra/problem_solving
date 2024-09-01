
// Problem link : https://leetcode.com/problems/power-of-four/

let isPowerOfFour = function(n) {
    let exp1 = n > 0 && (n & (n-1)) === 0
    let exp2 = (n & 0xAAAAAAAA) === 0;
    return exp1 && exp2;
};

// let num = 16;

let num = 26;
console.log(isPowerOfFour(num));
