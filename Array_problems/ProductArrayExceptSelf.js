
// Problem link : https://leetcode.com/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=top-100-liked

let productExceptSelf = function(nums) {
    const len = nums.length;
    let ansArr = new Array(len).fill(1);

    // compute left product
    let leftProduct = 1;
    for(let i=0; i<len; i++){
        ansArr[i] = leftProduct
        leftProduct *= nums[i];
    }

    // compute right product and combine it with right product
    let rightProduct = 1;
    for(let i = len-1; i>=0; i--){
        ansArr[i] *= rightProduct;
        rightProduct *= nums[i];
    }

    return ansArr
};

let nums = [1, 2, 3, 4];
console.log(productExceptSelf(nums));
