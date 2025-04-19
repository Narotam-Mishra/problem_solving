
// Problem link - https://leetcode.com/problems/calculate-digit-sum-of-a-string/description/?envType=problem-list-v2&envId=string

let digitSum = function(s, k) {
    // step 1 - continue until input string `s` length is greater than `k`
    while(s.length > k){
        // store newly transformed string `s` to a variable `newStr`
        let newStr = "";

        // step 2 - process string `s` in k chunks
        for(let i=0; i<s.length; i+=k){
            let group = s.slice(i, i+k);

            // step 3 - calculate sum of digits in each group
            let sum = 0;
            for(let digit of group){
                sum += parseInt(digit);
            }

            // step 4 - append the digit sum to the new string
            newStr += sum.toString();
        }

        // step 5 - update `s` to newly formed string `s`
        s = newStr;
    }

    // step 6 - return the final string once its length is <= k
    return s;
};

// const s = "11111222223", k = 3;

const s = "00000000", k = 3;
console.log(digitSum(s, k));
