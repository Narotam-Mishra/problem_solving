
// Problem link : https://leetcode.com/problems/longest-common-prefix/description/

let longestCommonPrefix = function(strs) {
    //corner case: if the array is empty, return ""
    if(!strs.length) return "";
    
    // start with the first string as the prefix
    let prefix = strs[0];

    // iterate on the string array
    for(let i=1; i<strs.length; i++){
        while(!strs[i].startsWith(prefix)){
            // shorten the prefix until it's a prefix of strs[i]
            prefix = prefix.substring(0, prefix.length-1);
        }
        // if prefix becomes empty, return ""
        if(!prefix) return "";
    }
    return prefix;
};

// let strs = ["flower","flow","flight"];

let strs = ["dog","racecar","car"];
console.log(longestCommonPrefix(strs));

