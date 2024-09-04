
// Problem link : https://leetcode.com/problems/convert-a-number-to-hexadecimal/description/?envType=problem-list-v2&envId=bit-manipulation

let toHex = function(num) {
    // handle the edge case for 0
    if(num === 0){
        return "0";
    }

    // handle negative numbers using two's complement
    if(num < 0){
        num += 2 ** 32;
    }

    // convert to hexadecimal string
    return num.toString(16);
};

// let num = 26

let num = -1
console.log(toHex(num));
