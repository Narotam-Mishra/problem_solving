
// Problem link - https://leetcode.com/problems/maximum-value-of-a-string-in-an-array/description/?envType=problem-list-v2&envId=string

let maximumValue = function(strs) {
    // step 1 - initialize variable to find maximum value of `strs`
    let maxVal = 0;

    // step 2 - iterate on each str of `strs` 
    for(let str of strs){
        if(isNaN(str)){
            // step 3 - if str is not number then find its length
            let len = str.split('').length;
            // and update maximum value
            maxVal = Math.max(maxVal, len);
        }else{
            // step 4 - otherwise find maximum numeric value
            maxVal = Math.max(maxVal, Number(str))
        }
    }

    // step 5 - return maximum value
    return maxVal;
};

// const strs = ["alic3","bob","3","4","00000"];

const strs = ["1","01","001","0001"];
console.log(maximumValue(strs));

