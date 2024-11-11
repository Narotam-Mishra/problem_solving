
// Problem link : https://leetcode.com/problems/power-of-three/description/

let isPowerOfThree = function(n) {
    // base case:
    if(n < 1) return false;

    // loop case:
    while(n % 3 === 0){
        n = Math.floor(n/3);
    }
    return n === 1; 
};

// let num = 27;

// let num = 0;

let num = -1;
console.log(isPowerOfThree(num));
