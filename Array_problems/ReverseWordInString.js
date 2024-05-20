
// Problem link - https://leetcode.com/problems/reverse-words-in-a-string/description/

// Approach - 1 (using Two Pointers)

let reverseWords = function(s) {
    // Split the string by any number of spaces and filter out empty strings
    let str = s.split(/\s+/).filter(word => word.length>0);

    // using Two pointer technique
    let l = 0, r = str.length - 1;
    while(l < r){
        let temp = str[l];
        str[l] = str[r];
        str[r] = temp;
        l++;
        r--;
    }
    return str.join('');
};