
// Problem link - https://leetcode.com/problems/squares-of-a-sorted-array/description/

// Approach - 1 (Brute Force)
// TC - O(n * log n)
let sortedSquares = function(nums) {
    for(let i=0; i<nums.length; i++) {
        nums[i] = nums[i] * nums[i];
    }
    nums.sort((a,b) => a-b);
    return nums;
};


// Approach - 2 (Two Pointers)

let sortedSquares1 = function(nums) {
    let l = 0;
    let r = nums.length - 1;
    let res = [];

    // to handle edge cases
    if(nums.length === 1){
        nums[0] = nums[0]**2;
        return nums;
    }

    while(l<r){
        for(let i=nums.length-1; i>=0; i--){
            if(nums[l]**2 < nums[r]**2){
                res[i] = nums[r]**2;
                r--;
            }else{
                res[i] = nums[l]**2;
                l++;
            }
        }
    }
    return res;
};