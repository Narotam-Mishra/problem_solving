
// Problem link - https://leetcode.com/problems/sum-of-two-integers/description/?envType=problem-list-v2&envId=bit-manipulation

let getSum = function(a, b) {
    while(b !== 0){
        // calculate the carry
        let carry = (a & b) << 1;

        // find sum without carry
        a = a ^ b;

        // assign carry to b and repeat
        b = carry;
    }
    return a;
};

// let a = 1, b = 2;

let a = 2, b = 3;
console.log(getSum(a, b));
