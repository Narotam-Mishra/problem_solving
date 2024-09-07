
// Problem link : https://leetcode.com/problems/number-complement/?envType=problem-list-v2&envId=bit-manipulation

let findComplement = function(num) {
    // step 1: find the bit length of the number
    let bitLength = num.toString(2).length;

    // step 2: create a mask of the same length with all bits set to 1
    const bitMask = (1 << bitLength) - 1;

    // step 3: XOR the number with the mask to get the complement
    return num ^ bitMask;
};

// let num = 5;

let num = 1;
console.log(findComplement(num));
