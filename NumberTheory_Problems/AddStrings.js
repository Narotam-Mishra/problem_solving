
// Problem link : https://leetcode.com/problems/add-strings/

let addStrings = function(num1, num2) {
    // initialize variables 'res' and 'carry' to store the result and the carry
    let res = '';
    let carry = 0;

    // initialize pointers for num1 and num2
    let i = num1.length - 1;
    let j = num2.length - 1;

    // loop through num1 and num2 from right to left
    while(i>=0 || j>=0){
        // calculate the sum of the current digits and the carry
        let sum = carry;
        if(i >= 0) sum += parseInt(num1[i--]);
        if(j >= 0) sum += parseInt(num2[j--]);

        // update carry and result 'res'
        res = (sum % 10) + res;
        carry = Math.floor(sum/10);
    }

    // if there's still a carry, add it to the result
    if(carry > 0){
        res = carry + res;
    }
    return res;
};

// let num1 = "11", num2 = "123";

// let num1 = "456", num2 = "77";

let num1 = "0", num2 = "0";
console.log(addStrings(num1, num2));
