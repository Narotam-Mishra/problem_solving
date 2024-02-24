
// Problem link - https://leetcode.com/problems/move-zeroes/description/

// Approach - 1 (swap no-zero numbers)
let moveZeroes = function(nums) {
    let k = 0;
    for(let i=0; i<nums.length; i++){
        if(nums[i] !== 0){
            let temp = nums[i];
            nums[i] = nums[k];
            nums[k] = temp;
            k++;
        }
    }
};