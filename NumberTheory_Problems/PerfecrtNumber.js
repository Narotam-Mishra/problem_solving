
// Problem link : https://leetcode.com/problems/perfect-number/description/

let checkPerfectNumber = function(num) {
    // edge case: perfect numbers are greater than 1
    if(num <= 1) return false;

    // start 'sum' with 1 as it is a divisor of every number
    let sum = 1;

    // loop from 2 to sqrt(n) to find divisors
    for(let i=2; i<=Math.sqrt(num); i++){
        if(num % i === 0){
            // if i divides n, add i as a divisor
            sum += i;

            // add n/i if it is distinct divisor
            if(i !== num/i) sum += num/i;
        }
    }

    // return true if sum equals input number 'num'
    return sum == num;
};

// let num = 6;

let num = 28;
console.log(checkPerfectNumber(num));
