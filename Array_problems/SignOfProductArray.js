
// Problem link - https://leetcode.com/problems/sign-of-the-product-of-an-array/

let arraySign = function(nums) {
    let countNegatives = 0;
    for(let i=0; i<nums.length; i++){
        if(nums[i] === 0){
            return 0;
        }else if(nums[i] < 0){
            countNegatives += 1;
        }
    }
    return countNegatives % 2 === 0 ? 1 : -1;
};

// let nums = [-1,-2,-3,-4,3,2,1];

// let nums = [1,5,0,2,-3]

let nums = [-1,1,-1,1,-1]
console.log(arraySign(nums));