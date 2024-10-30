
// Problem link : https://leetcode.com/problems/ugly-number/description/

let isUgly = function(n) {
    // corner case: Ugly numbers are defined as positive integers only.
    // If n is 0 or negative, it's not an ugly number.
    if(n <= 0) return false;

    // list of allowed prime factors
    const factors = [2, 3, 5];

    // for each allowed factor, divide n by the factor until it's no longer divisible.
    for(let factor of factors){
        while(n % factor === 0){
            // remove one occurrence of the factor.
            n = n / factor;
        }
    }

    // after removing all 2, 3, and 5 factors, check if n is reduced to 1.
    // if n is 1, it's an ugly number (only has factors of 2, 3, or 5).
    return n === 1;
};

// let num = 6;
// console.log(isUgly(num));

// let num = 14;
// console.log(isUgly(num));

let num = 1;
console.log(isUgly(num));
