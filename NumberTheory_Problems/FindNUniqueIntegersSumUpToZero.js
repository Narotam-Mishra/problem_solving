
// Problem link - https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/description/?envType=daily-question&envId=2025-09-07

let sumZero = function(n) {
    // store result in `res`
    const res = [];

    // edge case - if `n` is odd add 0 in resutant array `res`
    if(n % 2 === 1){
        res.push(0);
    }

    // step 1 - iterate from 1 to n/2 
    for(let i=1; i<=Math.floor(n/2); i++){
        // step 2 - add number and its negative that can sum up to 0
        res.push(i);
        res.push(-i);
    }

    // step 3 - return res
    return res;
};

// const n = 5;

// const n = 3;

const n = 1;
console.log(sumZero(n));