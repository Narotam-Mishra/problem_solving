
// Problem link - https://leetcode.com/problems/sum-of-digits-of-string-after-convert/description/?envType=problem-list-v2&envId=string

let getLucky1 = function(s, k) {
    // step 1 - convert string to digit string
    let digitStr = '';
    for(let ch of s){
        digitStr += ch.charCodeAt(0) - 96;
    }

    // step 2 - repeat k times : digit sum
    let sum = 0;
    while(k > 0){
        sum = 0;
        for(let digit of digitStr){
            sum += parseInt(digit, 10);
        }
        digitStr = sum.toString();
        k--;
    }

    // step 3 - return final digit sum
    return parseInt(digitStr, 10);
};

let getLucky = function(s, k) {
    // step 1 - convert each character in the string to its corresponding position in the alphabet
    // and calculate the sum of its digits.
    let sum = 0;
    for (let ch of s) {
        // convert character to its alphabet position (1-based).
        let digit = ch.charCodeAt(0) - 96;
        
        // add the sum of the digits of the position.
        sum += Math.floor(digit / 10) + (digit % 10); 
    }

    // step 2 - perform the transformation k times.
    for (let i = 1; i < k; i++) {
        let nextSum = 0;
        // calculate the sum of digits of the current sum.
        while (sum > 0) {
            // add the last digit of the sum.
            nextSum += sum % 10;

            // remove the last digit.
            sum = Math.floor(sum / 10); 
        }

        // update sum with the new calculated sum.
        sum = nextSum; 
    }

    // step 3 - return the final sum after k transformations.
    return sum;
};

// const s = "iiii", k = 1;

// const s = "leetcode", k = 2;

const s = "zbax", k = 2;
console.log(getLucky(s, k));
