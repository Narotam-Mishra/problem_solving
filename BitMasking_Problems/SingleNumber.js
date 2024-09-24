
// Problem link : https://leetcode.com/problems/single-number/description/?envType=problem-list-v2&envId=bit-manipulation

let singleNumber = function(nums) {
    let res = 0;
    for(num of nums){
        res = res ^ num;
    }
    return res;
};

// let nums = [2, 2, 1]

let nums = [4, 1, 2, 1, 2]
console.log(singleNumber(nums));
