
// Problem link : https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/description/?envType=problem-list-v2&envId=hash-table

// Approach 1: Brute Force

//  helper function to check if substring is valid
function isValidSubstring(str){
    let map = {};
    for(let ch of str){
        map[ch] = (map[ch] || 0) + 1;
        if(map[ch] > 2) return false;
    }
    return true;
}

let maximumLengthSubstring1 = function(s) {
    // step 1 - create variable to store maximum length of substring with given condition
    let maxLen = 0;

    // step 2 - try all possible substring
    for(let i=0; i<s.length; i++){
        // step 3 - check if current substring is valid
        for(let j=i; j<s.length; j++){
            const subString = s.slice(i, j+1);
            if(isValidSubstring(subString)){
                // step 4 - calculate maximum length of substring
                maxLen = Math.max(maxLen, j-i+1);
            }
        }
    }

    // step 5 - return maximum length of substring
    return maxLen;
};

// Approach - 2 Using Sliding Window with Map 
let maximumLengthSubstring = function (s) {
  //   step 1 - initialize variables
  let maxLen = 0;
  const charMap = {};
  let start = 0;

  // step 2 - Iterate through each character in the sliding window
  for (let end = 0; end < s.length; end++) {
    // add current character to our count
    let curChar = s[end];
    charMap[curChar] = (charMap[curChar] || 0) + 1;

    // step 3 - while window becomes invalid (any char appears more than twice)
    // shrink window from start
    while (charMap[curChar] > 2) {
      let startChar = s[start];
      charMap[startChar]--;
      start++;
    }

    // step 4 - update maximum length of substring
    maxLen = Math.max(maxLen, end - start + 1);
  }

  // step 5 - return maximum length of substring
  return maxLen;
};

// const s = "bcbbbcba";

const s = "aaaa";
console.log(maximumLengthSubstring(s)); 
