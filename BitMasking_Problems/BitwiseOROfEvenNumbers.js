
// Problem link - https://leetcode.com/problems/bitwise-or-of-even-numbers-in-an-array/description/?envType=problem-list-v2&envId=array

let evenNumberBitwiseORs = function(nums) {
    // store final result in `res`
    let res = 0;

    // step 1 - iterate on each number of `nums`
    for(let num of nums){
        // step 2 - check if it is even number or not
        if(num % 2 === 0){
            // step 3 - calculate bitwise OR of even number 
            // and store result in `res`
            res = res | num;
        }
    }

    // step 4 - return final result `res`
    return res;
};

// const nums = [1,2,3,4,5,6];

// const nums = [7,9,11];

const nums = [1,8,16]
console.log(evenNumberBitwiseORs(nums));