
// Problem link - https://leetcode.com/problems/find-the-integer-added-to-array-i/description/?envType=problem-list-v2&envId=array

let addedInteger1 = function(nums1, nums2) {
    // step 1 - sort both arrays for one-to-one correspondence between every element
    nums1.sort((a,b) => a - b);
    nums2.sort((a,b) => a - b);

    // step 2 - calculate the value of `x`
    let x = nums2[0] - nums1[0];

    // step 3 - return value of `x`
    return x;
};

let addedInteger = function(nums1, nums2) {
    return Math.min(...nums2) - Math.min(...nums1);
};

// const nums1 = [2,6,4], nums2 = [9,7,5];

// const nums1 = [10], nums2 = [5];

const nums1 = [1,1,1,1], nums2 = [1,1,1,1];
console.log(addedInteger(nums1, nums2));