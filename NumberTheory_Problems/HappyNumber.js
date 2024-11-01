
// Problem link : https://leetcode.com/problems/happy-number/

let isHappy = function(n) {
    // create a set to store visited numbers for cycle detection
    const visited = new Set();

    // continue process until termination
    while(n !== 1 && !visited.has(n)){
        // add current number to visited set
        visited.add(n);

        // store sum of square of digits in sum
        let sum = 0;

        // calculate sum of squares of digits
        while(n > 0){
            // extract last digit
            let digit = n % 10;

            // square and add to sum
            sum += digit * digit;

            // extract last digit from number 'n'
            n = Math.floor(n / 10);
        }

        // update n for next iteration
        n = sum;
    }
    // return true if n reached 1 (happy number), false otherwise
    return n === 1;
};

// let num = 19;

let num = 2;
console.log(isHappy(num));
