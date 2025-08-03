
// Problem link - https://leetcode.com/problems/finding-3-digit-even-numbers/?envType=problem-list-v2&envId=array

// Approach 1 - Using Brute Force 

let findEvenNumbers1 = function(digits) {
    // step 1 - store unique even numbers in `validEvenNums` set
    const validEvenNums = new Set();
    
    // step 2 - generate all possible 3-digits numbers
    const n = digits.length;
    for(let i=0; i<n; i++){
        for(let j=0; j<n; j++){
            for(let k=0; k<n; k++){
                // step 3 - make sure all digits are from different positions
                if(i === j || j === k || i === k) continue;

                // first digit
                const d1 = digits[i];

                // second digit
                const d2 = digits[j];

                // third digit
                const d3 = digits[k];

                // step 3 - check the given conditions
                // condition 1 - no leading zero, so skip leading zero
                if(d1 === 0) continue;

                // condition 2 - number must be even, hence skip odd number
                if(d3 % 2 !== 0) continue;

                // step 4 - form three digit number
                const num = d1*100 + d2*10 + d3;

                // step 5 - store three number in `validEvenNums` set
                validEvenNums.add(num);
            }
        }
    }

    // step 6 - return unique three digit even numbers in asceding order in array
    return Array.from(validEvenNums).sort((a,b) => a - b);
};

// Optimal Approach

// utility function to check if we can form a number using available digits
function canFormNumber(requiredDigits, availableDigits){
    // count how many of each digit we need
    const neededMap = new Map();
    for(let digit of requiredDigits){
        neededMap.set(digit, (neededMap.get(digit) || 0) + 1);
    }

    // check if we have enough of each required digits
    for(let [digit, count] of neededMap){
        const available = availableDigits.get(digit) || 0;
        if(available < count){
            return false;
        }
    }

    return true;
}

let findEvenNumbers2 = function(digits) {
    // step 1 - store frequency of each digit in `digitsMap` map
    const digitsMap = new Map();
    for(let digit of digits){
        digitsMap.set(digit, (digitsMap.get(digit) || 0) + 1);
    }

    // step 2 - check each possible even 3-digit number from 100 to 999
    const validEvenNums = [];
    for(let num=100; num<=999; num+=2){
        //step 3 - extract each digit from current number
        const hundreads = Math.floor(num / 100);
        const tens = Math.floor((num % 100) / 10);
        const units = num % 10;

        // step 4 - check if we can form this number from available digits in `digitsMap`
        if(canFormNumber([hundreads, tens, units], digitsMap)){
            validEvenNums.push(num);
        }
    }

    // step 5 - return `validEvenNums` array as it is already sorted since we iterate in ascending order
    return validEvenNums;
};

let findEvenNumbers = function(digits) {
    // step 1 - store frequency of each digit in counts
    const counts = new Array(10).fill(0);
    for(let digit of digits){
        counts[digit]++;
    }

    // step 2 - check each possible even 3-digit number from 100 to 999
    const validEvenNums = [];
    for(let num=100; num<=999; num+=2){
      //step 3 - extract each digit from current number
      const hundreds = Math.floor(num / 100);
      const tens = Math.floor((num % 100) / 10);
      const units = num % 10;

      // step 4 - check if we can form this number from available digits in `digitsMap`
      counts[hundreds]--, counts[tens]--, counts[units]--;
      if (counts[hundreds] >= 0 && counts[tens] >= 0 && counts[units] >= 0) {
        // store this number into valid even number array
        validEvenNums.push(num);
      }

      // step 5 - restore the count to check other combination of number
      counts[hundreds]++, counts[tens]++, counts[units]++;
    }

    // step 6 - return `validEvenNums` array as it is already sorted since we iterate in ascending order
    return validEvenNums;
};

const digits = [2,1,3,0];

// const digits = [2,2,8,8,2];

// const digits = [3,7,5];
console.log(findEvenNumbers(digits));