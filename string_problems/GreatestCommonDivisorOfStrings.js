
// Problem link : https://leetcode.com/problems/greatest-common-divisor-of-strings/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

// helper function to find GCD of two numbers
function findGCD(a, b){
    return b === 0 ? a : findGCD(b, a % b);
}

let gcdOfStrings = function(str1, str2) {
    // step 1: check if concatenated strings are equal
    if(str1 + str2 !== str2 + str1){
        return "";
    }

    // step 2: calculate GCD of lengths
    const gcdLen = findGCD(str1.length, str2.length);

    // step 3: the GCD string is the prefix of either string of length gcdLen
    return str1.substring(0, gcdLen);
};

let str1 = "ABCABC", str2 = "ABC";

// let str1 = "ABABAB", str2 = "ABAB";

// let str1 = "LEET", str2 = "CODE";
console.log(gcdOfStrings(str1, str2));
