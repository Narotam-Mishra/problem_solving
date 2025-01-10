
// Problem link : https://leetcode.com/problems/find-the-difference-of-two-arrays/description/?envType=problem-list-v2&envId=hash-table

let findDifference = function(nums1, nums2) {
    // step 1 - create sets from the input arrays
    const set1 = new Set(nums1);
    const set2 = new Set(nums2);

    // step 2 - find elements unique to nums1
    const uniqueToNums1 = [...set1].filter(num => !set2.has(num));

    // step 3 - find elements unique to nums2
    const uniqueToNums2 = [...set2].filter(num => !set1.has(num));
    
    // step 4 - return the result as an array of two arrays
    return [uniqueToNums1, uniqueToNums2];
};

// const nums1 = [1,2,3], nums2 = [2,4,6];

const nums1 = [1,2,3,3], nums2 = [1,1,2,2];
console.log(findDifference(nums1, nums2));
