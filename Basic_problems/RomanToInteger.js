
// Problem link : https://leetcode.com/problems/roman-to-integer/description/

let romanToInt = function(s) {
    const romanMap = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    };

    let res = 0;
    for(let i=0; i<s.length; i++){
        if(i < s.length-1 && romanMap[s[i]] < romanMap[s[i+1]]){
            res -= romanMap[s[i]];
        }else{
            res += romanMap[s[i]];
        }
    }
    return res;
};

// let str = "III";

// let str = "LVIII";

let str = "MCMXCIV";
console.log(romanToInt(str));
