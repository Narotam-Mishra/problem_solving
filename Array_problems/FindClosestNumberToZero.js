
// Problem link - https://leetcode.com/problems/find-closest-number-to-zero/description/?envType=problem-list-v2&envId=array

let findClosestNumber = function(nums) {
    // step 1 - assume first number of `nums` as closest number 
    let closestNum = nums[0];

    // step 2 - iterate through the rest of the array starting from index 1
    for(let i=1; i<nums.length; i++){
        let currNum = nums[i];

        // step 3 - calculate absolute distances from 0
        let currDistance = Math.abs(currNum);
        let closestDistance = Math.abs(closestNum);

        // step 4 - check if current number is closer to 0
        if(currDistance < closestDistance){
            closestNum = currNum;
        }else if(currDistance === closestDistance){
            // step 5 - if distances are equal, we need to pick the larger number
            closestNum = Math.max(currNum, closestNum);
        }
    }

    // step 6 - return closest number `closestNum`
    return closestNum;
};

const nums = [-4,-2,1,4,8];

// const nums = [2,-1,1];
console.log(findClosestNumber(nums));