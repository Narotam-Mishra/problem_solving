
// Problem link : https://leetcode.com/problems/reformat-the-string/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

let reformat = function(s) {
    // step 1 - separate the letters and digits into two arrays
    const letters = [];
    const digits = [];

    for(let ch of s){
        if(isNaN(ch)){
            // add to letters if the character is not a digit
            letters.push(ch);
        }else{
            // add to digits if the character is a digit
            digits.push(ch);
        }
    }

    // step 2 - check if it is impossible to reformat
    if(Math.abs(letters.length - digits.length) > 1){
        // return an empty string
        return "";
    }

    // step 3 - decide which group should start based on their sizes
    let largerGrp = letters;
    let smallerGrp = digits;
    if(digits.length > letters.length){
        largerGrp = digits;
        smallerGrp = letters;
    }

    // step 4 - interleave characters from both groups
    const res = [];
    while(largerGrp.length || smallerGrp.length){
        if(largerGrp.length) res.push(largerGrp.pop());
        if(smallerGrp.length) res.push(smallerGrp.pop());
    }

    // step 5 -  join the result array into a string and return it
    return res.join('');
};

let str = "a0b1c2";

// let str = "leetcode";

// let str = "1229857369";
console.log(reformat(str));
