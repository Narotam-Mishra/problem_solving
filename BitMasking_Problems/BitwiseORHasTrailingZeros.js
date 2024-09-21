
// Problem link : https://leetcode.com/problems/check-if-bitwise-or-has-trailing-zeros/description/?envType=problem-list-v2&envId=bit-manipulation

/*

Logic - As we know each even number has trailing 0 in their binary representation so when we do bitwise OR of even number with another even number it will always give a trailing zeros. So if array has just two numbers which are even that will suffice the given condition in problem.

*/

let hasTrailingZeros = function(nums) {
    let count = 0;
    for(let num of nums){
        if((num & 1) !== 1) count++
    }
    return count >=2
};

// let nums = [1, 2, 3, 4, 5]

// let nums = [2, 4, 8, 16]

let nums = [1, 3, 5, 7, 9]
console.log(hasTrailingZeros(nums));
