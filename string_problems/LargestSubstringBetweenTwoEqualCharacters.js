
// Problem link : https://leetcode.com/problems/largest-substring-between-two-equal-characters/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

let maxLengthBetweenEqualCharacters = function(s) {
    // step 1 - initialize a map to store the first occurrence of each character
    const map = new Map();

    // step 2 - variable to store the maximum length of substring found
    let maxLength = -1;

    // step 3 - iterate through the string and find largest sbstring length
    for(let i=0; i<s.length; i++){
        let curChar = s[i];

        // check if the current character has been seen before
        if(map.has(curChar)){
            // calculate the length of the largest substring between the two occurrences
            const lengthBetween = i - map.get(curChar) - 1;

            // update the maximum substring length
            maxLength = Math.max(maxLength, lengthBetween);
        }else{
            // store the first occurrence index of the character
            map.set(curChar, i);
        }
    }

    // step 4 - return the maximum length found, or -1 if no such substring exists
    return maxLength;
};

// const str = "aa";

const str = "cbzxy";
console.log(maxLengthBetweenEqualCharacters(str));
