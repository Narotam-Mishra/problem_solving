
// Problem link : https://leetcode.com/problems/second-largest-digit-in-a-string/description/?envType=problem-list-v2&envId=hash-table

let secondHighest1 = function(s) {
    // step 1 - create a Set to store unique digits
    const uniqueDigits = new Set();

    // step 2 - iterate through the string and extact all the digits
    for(let ch of s){
        // check if the character is a digit
        if(!isNaN(ch) && ch >= '0' && ch <= '9'){
            // add digit (converted to a number) to the Set
            uniqueDigits.add(Number(ch));
        }
    }

    // step 3 - convert the Set to an array and sort it in descending order
    const sortedDigits = Array.from(uniqueDigits).sort((a,b) => b-a);

    // step 4 - check if there is a second largest digit
    return sortedDigits.length >= 2 ? sortedDigits[1] : -1;
};

let secondHighest = function(s) {
    // step 1 - initialize largest and second largest variables
    let largest = -1;
    let secondLargest = -1;

    // step 2 - iterate through each character in the string
    for(let ch of s){
        if(ch >= '0' && ch <= '9'){
            const digit = Number(ch);
            // step 3 - find second largest
             // if current digit is greater than largest
            if(digit > largest){
                // current largest becomes second largest
                secondLargest = largest;

                // update largest
                largest = digit;

            // if digit is less than largest but greater than second largest
            } else if(digit < largest && digit > secondLargest){
                secondLargest = digit;
            }
        }    
    }

    // step 4 - return the second largest digit
    return secondLargest;
};

const s = "dfa12321afd";

// const s = "abc1111";
console.log(secondHighest(s)); 