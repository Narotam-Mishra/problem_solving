
// Problem link - https://leetcode.com/problems/add-binary/description/

// utility method to convert binary numbers to decimal
function binaryToDecimal(binStr){
    return BigInt("0b" + binStr);
}

// utility method to convert decimal numbers to binary
function decimalToBinary(decNum){
    return decNum.toString(2);
}

let addBinary = function(a, b) {
    a = binaryToDecimal(a);
    b = binaryToDecimal(b);

    let sum = a + b;
    return decimalToBinary(sum);
};

// let a = "1010", b = "1011"

// long inputs
const a = "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101";
const b = "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011";

console.log(addBinary(a, b));