
// Problem link : https://leetcode.com/problems/largest-odd-number-in-string/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

let largestOddNumber1 = function(num) {
    // initialize a variable to store the largest odd substring
    let largestOdd = "";

    // traverse the string character by character
    for(let i=0; i<num.length; i++){
        // extract the current character
        let char = num[i];

        // check if the character is an odd digit
        if(char === '1' || char === '3' || char === '5' || char === '7' || char === '9'){
            // if it's odd, the current substring from the start to this index is valid
            let curOdd = num.slice(0, i+1);

            // update the largestOdd if the current substring is greater
            if(curOdd > largestOdd){
                largestOdd = curOdd;
            }
        }
    }
    // return the largest odd substring found, or an empty string if none exists
    return largestOdd;
};

let largestOddNumber = function(num) {
    // start from the last digit and move backward
    for(let i=num.length-1; i>=0; i--){
        // convert the character to a number and check if it's odd
        if(Number(num[i]) % 2 !== 0){
            // if odd, return the substring from the start to this position
            return num.slice(0, i+1);
        }
    }
    // if no odd digit is found, return an empty string
    return "";
};

let num = "52";

// let num = "4206";

// let num = "35427";
console.log(largestOddNumber(num));
