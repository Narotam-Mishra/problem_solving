
// Problem link : https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value/description/?envType=problem-list-v2&envId=hash-table

let digitCount = function(num) {
    // step 1 - create map using array to store frquency of each digit
    const numMap = new Array(10).fill(0);
    for(let i=0; i<num.length; i++){
        numMap[Number(num[i])]++
    }

    // step 2 - iterate num array (digit by digit) to check its frquency
    for(let i=0; i<num.length; i++){
        // if digit frquency is not equal return false
        if(Number(num[i]) !== numMap[i]){
            return false;
        }
    }

    // step 3 - otherwise return true 
    return true;
};

// const num = "1210"

const num = "030"
console.log(digitCount(num));
