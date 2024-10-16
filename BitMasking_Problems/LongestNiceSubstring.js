
// Problem link : https://leetcode.com/problems/longest-nice-substring/description/?envType=problem-list-v2&envId=bit-manipulation&status=TO_DO&difficulty=EASY

// helper function to check if a substring is "nice"
function isNiceString(str){
    // use a set to store unique characters in the substring
    const strSet = new Set(str);

    // check if every character in the set has both its uppercase and lowercase versions present
    for(const char of strSet){
        // if either the lowercase or uppercase version is missing, the string is not "nice"
        if(!strSet.has(char.toUpperCase()) || !strSet.has(char.toLowerCase())){
            return false;
        }
    }
    return true;
}

let longestNiceSubstring = function(s) {
    // variable 'maxLen' to keep track of the maximum length of a "nice" substring
    let maxLen = 0
    
    // variable to store the longest "nice" substring
    let res = "";

    // iterate over all possible substrings of the string
    for(let i=0; i<s.length; i++){
        for(let j=i+1; j<=s.length; j++){
            // extract substring from index i to j-1
            let subStr = s.slice(i, j);

             // check if the current substring is "nice"
            if(isNiceString(subStr) && subStr.length > maxLen){
                // ppdate maxLength if a longer "nice" substring is found
                maxLen = subStr.length;
                
                // store the new longest "nice" substring
                res = subStr;
            }
        }
    }

    // return the longest "nice" substring found, or an empty string if none exist
    return res;
};

// let str = "YazaAay";

// let str = "Bb";

let str = "c";
console.log(longestNiceSubstring(str));
