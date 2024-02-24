
// Problem link - https://leetcode.com/problems/4sum/description/

// Approach - 1 (Two Pointers)
// TC - O(n^3)

let fourSum = function(nums, target) {
    // sort the array 
    nums.sort((a,b) => a-b);
    const resArr = [];

    for(let i=0; i<nums.length-3; i++){
        for(let j=i+1; j<nums.length-2; j++){
            let l = j+1; r = nums.length - 1, sum=0;

            // Using Two Pointers Approach
            while(l < r){
                sum = nums[i] + nums[j] + nums[l] + nums[r];
                
                if(sum === target){
                    resArr.push([nums[i], nums[j], nums[l], nums[r]]);
                    // avoid duplicates
                    while(nums[l] === nums[l+1]) l++;
                    while(nums[r] === nums[r-1]) r--;
                    l++;
                    r--;
                }else if(sum > target){
                    r--;
                }else{
                    l++;
                }
            }
            // avoid duplicates
            while(nums[j] === nums[j+1]) j++;
        }
        // avoid duplicates
        while(nums[i] === nums[i+1]) i++
    }
    return resArr;
};