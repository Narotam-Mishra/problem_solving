
// Problem link : https://leetcode.com/problems/consecutive-characters/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

let maxPower = function(s) {
    // initialize variables
    // start with the first character
    let currChar = s[0];
    
    // length of the current sequence
    let curPow = 1;

    // at least one character guarantees power 1
    let maxPower = 1;
    
     // iterate through the string starting from the second character
    for(let i=1; i<s.length; i++){
        if(s[i] === currChar){
            // continue the sequence
            curPow++;
        }else{
            // sequence ends, update maxPower if needed
            maxPower = Math.max(maxPower, curPow);
            
            // reset for the new character
            currChar = s[i];
            curPow = 1;
        }
    }

    // final comparison to account for the last sequence
    maxPower = Math.max(maxPower, curPow);
    return maxPower;
};

// let str = "leetcode";

let str = "abbcccddddeeeeedcba";
console.log(maxPower(str));
