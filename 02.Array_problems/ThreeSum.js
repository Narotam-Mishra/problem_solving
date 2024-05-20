
// Problem link - https://leetcode.com/problems/3sum/description/

// Approach - 1 (using Two Pointers)
let threeSum = function(nums) {
    // sort the array
    nums.sort((a,b) => a-b);
    const resArr = [];

    for(let i=0; i<nums.length; i++) {

        // avoid duplicates
        if(i > 0 && nums[i] === nums[i-1]) continue;

        let l = i+1, r = nums.length - 1, sum = 0;

        // using two pointers approach 
        while(l<r){
            sum = nums[i] + nums[l] + nums[r];

            if(sum === 0){
                resArr.push([nums[i], nums[l], nums[r]]);
                // avoid duplicates
                while(nums[l] === nums[l+1]) l++;
                while(nums[r] === nums[r-1]) r--;
                l++;
                r--;
            }else if(sum > 0){
                r--;
            }else{
                l++;
            }
        }
    }
    return resArr;
};


// Approach - 2

let threeSum1 = function(nums) {
    // sort the array
    nums.sort((a,b) => a-b);
    const resArr = [];

    for(let i=0; i<nums.length; i++) {

        let l = i+1, r = nums.length - 1, sum = 0;

        // using two pointers approach 
        while(l<r){
            sum = nums[i] + nums[l] + nums[r];

            if(sum === 0){
                resArr.push([nums[i], nums[l], nums[r]]);
                // avoid duplicates
                while(nums[l] === nums[l+1]) l++;
                while(nums[r] === nums[r-1]) r--;
                l++;
                r--;
            }else if(sum > 0){
                r--;
            }else{
                l++;
            }
        }
        // avoid duplicates
        while(nums[i] === nums[i+1]) i++;
    }
    return resArr;
};