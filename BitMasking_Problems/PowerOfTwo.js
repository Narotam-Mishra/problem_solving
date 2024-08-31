
// Problem link : https://leetcode.com/problems/power-of-two/

let isPowerOfTwo = function(n) {
    // A power of two has exactly one bit set, 
    // so n > 0 and (n & (n - 1)) should be 0
    let res = (n & (n-1)) === 0
    return n > 0 && res;
};

// let num = 15;

let num = 16;
console.log(isPowerOfTwo(num));
