
// Problem link - https://leetcode.com/problems/build-array-from-permutation/description/?source=submission-ac

let buildArray = function(nums,len) {
    let res = [];
    for(let i=0; i<len; i++){
        res[i] = nums[nums[i]];
    }
    return res;
};

let arr = [0,2,1,5,3,4];
console.log(buildArray(arr,arr.length));