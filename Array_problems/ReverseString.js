
// Problem link - https://leetcode.com/problems/reverse-string/description/

// Approach - 1 (Brute Force)

function swapItems(str, s, e){
    let temp = str[s];
    str[s] = str[e];
    str[e] = temp;
}

let reverseString = function(str) {
    let s = 0;
    let e = str.length-1;
    
    while(s<e){
        swapItems(str, s, e);
        s++;
        e--;
    }
};