
// Problem link - http://leetcode.com/problems/find-valid-pair-of-adjacent-digits-in-string?envType=problem-list-v2&envId=hash-table

let findValidPair = function(s) {
    // step 1 - create a frequency map using fixed size array to count the occurrences of each digit in the string
    const mapArr = new Array(10).fill(0);

    // step 2 - populate the frequency map
    for(let digit of s){
        mapArr[(+digit)]++;
    }

    // step 3 - traverse the string to check for the first valid pair
    for(let i=0; i<s.length-1; i++){
        const firstDigit = +s[i];
        const secondDigit = +s[i+1];

        // a valid pair requires the two digits to be different
        if(firstDigit !== secondDigit){
            // check if the frequency of each digit matches its numeric value
            if(mapArr[firstDigit] === firstDigit && mapArr[secondDigit] === secondDigit){
                return s[i] + s[i+1];
            }
        }
    }

    // step 4 - if no valid pair is found, return an empty string
    return "";
};

const s = "2523533";

// const s = "221";

// const s = "22";
console.log(findValidPair(s));
