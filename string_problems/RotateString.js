
// Problem link : https://leetcode.com/problems/rotate-string/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

let rotateString = function(s, goal) {
    // cornor case: check if lengths are the same, 
    // if not, s can't be shifted to become goal
    if(s.length !== goal.length) return false;
    
    // concatenate s with itself to cover all possible rotations
    let doubleStr = s + s;

    // check if goal is a substring of doubleS
    return doubleStr.includes(goal);
};

// let s = "abcde", goal = "cdeab";

let s = "abcde", goal = "abced";
console.log(rotateString(s, goal));
