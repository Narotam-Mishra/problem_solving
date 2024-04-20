
// Problem link - https://leetcode.com/problems/find-the-duplicate-number/description/


let findDuplicate = function(nums) {
    // sort array numbers
    nums.sort((a,b) => a-b);

    for(let i=1; i<nums.length; i++){
        if(nums[i] === nums[i-1]){
            return nums[i];
        }
    }
    return;
};

let arr = [1,3,4,2,2];

// let arr = [3,1,3,4,2];

// let arr = [3,3,3,3,3];
console.log(findDuplicate(arr));