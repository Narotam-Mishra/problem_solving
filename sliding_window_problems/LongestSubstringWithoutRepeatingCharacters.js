
// Problem link - https://leetcode.com/problems/longest-substring-without-repeating-characters/

let lengthOfLongestSubstring1 = function(s) {
    // step 1 - initialize a Set to store unique characters in the current window
    const charSet = new Set();

    // step 2 - initialize two pointers `start` & `end` for the sliding window
    let start = 0;
    // use `maxLength`to keep track of the maximum length of the substring
    let maxLength = 0;

    // step 3 - iterate over the string using `end` pointer
    for(let end = 0; end < s.length; end++){
        // if the character at 'end' is already in the set, shrink the window
        while(charSet.has(s[end])){
            // remove the character at `start` from the set and move `start` forward
            charSet.delete(s[start]);
            start++;
        }

        // add the current character at 'end' to the set
        charSet.add(s[end]);
        
        // update maximum length of substring
        maxLength = Math.max(maxLength, end - start + 1);
    }

    // step 4 - return the maximum length found
    return maxLength;
};

let lengthOfLongestSubstring = function(s) {
    // step 1 : initialize a Map to store the characters and their most recent indices
    const map = new Map();

    // step 2 - initialize two pointers `start` & `end` for the sliding window
    let start = 0;
    let maxLength = 0;

    // step 3 - iterate over the string using `end` pointer
    for(let end = 0; end < s.length; end++) {
        const currChar = s[end];

        // if the character is already in the map, move the `start` pointer
        if(map.has(currChar)){
            // move the `start` pointer to the right of the previous index of the current character
            start = Math.max(start, map.get(currChar) + 1);
        }

        // update the most recent index of the current character
        map.set(currChar, end);
        
        // update maximum length of substring
        maxLength = Math.max(maxLength, end - start + 1);
    }

    // step 4: return the maximum length found
    return maxLength;
};

// const s = "abcabcbb";

// const s = "bbbbb";

const s = "pwwkew";
console.log(lengthOfLongestSubstring(s)); 
