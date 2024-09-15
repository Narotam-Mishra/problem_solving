
// Problem link : https://leetcode.com/problems/binary-prefix-divisible-by-5/description/?envType=problem-list-v2&envId=bit-manipulation

let prefixesDivBy5 = function(nums) {
    let num = 0
    let res = [];

    for(let i=0; i<nums.length; i++){
        num = (num * 2 + nums[i]) % 5;
        num === 0 ? res.push(true) : res.push(false);
    }
    return res;
};


let nums = [0, 1, 1]

// let nums = [1, 1, 1]
console.log(prefixesDivBy5(nums));
