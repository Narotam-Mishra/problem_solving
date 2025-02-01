
// Problem link : https://leetcode.com/problems/check-if-the-number-is-fascinating/description/?envType=problem-list-v2&envId=hash-table

let isFascinating1 = function(n) {
    const freq = new Array(10).fill(0);
    const num = n.toString() + (2*n).toString() + (3*n).toString();

    for(let i=0; i<num.length; i++){
        freq[num[i]]++
    }

    for(i=1; i<freq.length; i++){
        if(freq[i] !== 1) return false;
    }
    return true;
};

let isFascinating = function(n) {
    // step 1 - compute multiples as per problem
    let twice = 2*n
    let thrice = 3*n

    // step 2 - concatenate n, 2n, and 3n
    let concateNum = `${n}${twice}${thrice}`;

    // step 3 - check for required edge cases
    if(concateNum.length !== 9) return false;
    if(concateNum.includes('0')) return false;

    // step 4 - check if all digits 1-9 appear exactly once
    let digitSet = new Set(concateNum);
    return digitSet.size === 9;
};

const n = 192;

// const n = 100;
console.log(isFascinating(n));
