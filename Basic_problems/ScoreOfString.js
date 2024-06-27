
// Problem link - https://leetcode.com/problems/score-of-a-string/description/?envType=daily-question&envId=2024-06-01

let scoreOfString = function(s) {
    let absDiff = 0;
    for(let i=1; i<s.length; i++){
        absDiff+= Math.abs(s.charCodeAt(i-1) - s.charCodeAt(i));
    }
    return absDiff;
};

// let str = "hello"

let str = "zaz"
console.log(scoreOfString(str));