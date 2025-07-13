
// Problem link - https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/?envType=problem-list-v2&envId=array

let maxProduct = function(nums) {
    const n = nums.length;
    // step 1 - sort the `nums` array to get maximum numbers easily
    nums.sort((a,b) => a-b);

    // step 2 - get first two maximum numbers from `nums`
    // maximum numbers will be give maximum product
    let maxNum1 = nums[n-1] - 1;
    let maxNum2 = nums[n-2] - 1;

    // step 3 - calculate (nums[i]-1)*(nums[j]-1) and return the maximum product
    return (maxNum1 * maxNum2);
};

// const nums = [3,4,5,2];

// const nums = [1,5,4,5];

const nums = [3,7];
console.log(maxProduct(nums));