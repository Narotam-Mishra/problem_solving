
// Problem link : https://leetcode.com/problems/count-the-digits-that-divide-a-number/description/

let countDigits = function(num) {
    // intialize counter 'count' to keep track of count
    let count = 0;
    
    // conver to string for easy iteration
    let numStr = String(num);
    
    // iterate through each digit of string format number
    for(let i=0; i<numStr.length; i++) {
        // change digit to number
        let digit = Number(numStr[i]);

        if(digit !== 0 && num % digit === 0){
            // if each non-zero digit divde the number 'num', increment count
            count++;
        }
    }
    // return the count 
    return count;
};

// let num = 121;

// let num = 1248;

let num = 7;
console.log(countDigits(num));
