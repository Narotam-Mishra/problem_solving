
// Problem link : https://leetcode.com/problems/complement-of-base-10-integer/?envType=problem-list-v2&envId=bit-manipulation

let bitwiseComplement = function(n) {
    // step 1: find the bit length of the number
    let bitLength = n.toString(2).length;

    // step 2: create a mask of the same length with all bits set to 1
    const bitMask = (1 << bitLength) - 1;

    // step 3: XOR the number with the mask to get the complement
    return n ^ bitMask;
};

// let num = 5

// let num = 7

let num = 10
console.log(bitwiseComplement(num));
