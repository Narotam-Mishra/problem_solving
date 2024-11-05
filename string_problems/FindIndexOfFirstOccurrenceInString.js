
// Problem link : https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

let strStr = function(haystack, needle) {
    return haystack.indexOf(needle);
};

// let haystack = "sadbutsad", needle = "sad"

let haystack = "leetcode", needle = "leeto"
console.log(strStr(haystack, needle));
