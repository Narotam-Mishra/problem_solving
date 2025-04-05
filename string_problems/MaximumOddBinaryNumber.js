
// Problem link - https://leetcode.com/problems/maximum-odd-binary-number/description/?envType=problem-list-v2&envId=string

let maximumOddBinaryNumber = function(s) {
    // step 1 - count ones in binary string
    let countOnes = 0;
    for(let bit of s){
        if(bit === '1'){
            countOnes++;
        }
    }

    // step 2 - find number of zeroes in `s`
    const countZeroes = s.length - countOnes;

    // step 3 - rearrange binary numbers to from maximum odd binary number
    const res = '1'.repeat(countOnes - 1) + '0'.repeat(countZeroes) + '1';

    // step 4 - return result `res`
    return res;
};

// const s = "010";

const s = "0101";
console.log(maximumOddBinaryNumber(s));
