
// Problem link - https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/description/

let minimumSum = function(num) {
    // step 1 - extract all digits from the number
    // convert to string to easily access individual digits
    const digits = num.toString().split('').map(Number);

    // step 2 - sort digits in ascending order, this will ensure minimum sum
    digits.sort((a,b) => a- b);

    // step 3 - distribute digits optimally between two numbers
    // we want to distribute digits as evenly as possible
    const num1Digits = [];
    const num2Digits = [];

    // distribute digits alternately
    for(let i=0; i<digits.length; i++){
        if(i % 2 === 0){
            num1Digits.push(digits[i]);
        }else{
            num2Digits.push(digits[i])
        }
    }

    // step 4 - build the numbers from distributed digits
    // convert digit arrays back to numbers for easy addition 
    const new1 = parseInt(num1Digits.join(''));
    const new2 = parseInt(num2Digits.join(''));

    // step 5 - return the sum
    return new1 + new2;
};

// const num = 2932;

const num = 4009;
console.log(minimumSum(num));