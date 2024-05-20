
// Problem link - https://leetcode.com/problems/reverse-integer/description/

let reverse = function(x) {
    const isNegative = x < 0;
    let reversedNum = parseInt(Math.abs(x).toString().split('').reverse().join(''));

    // if given number x is negative
    if(isNegative) reversedNum *= -1;

    // check for overflow
    if(reversedNum < Math.pow(-2, 31) || reversedNum > Math.pow(2,31) - 1){
        return 0;
    }

    // return reversed number
    return reversedNum;
};

console.log(reverse(123)); // Output: 321
console.log(reverse(-123)); // Output: -321
console.log(reverse(120)); // Output: 21
console.log(reverse(1534236469)); // Output: 0 (overflow)