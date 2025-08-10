
// Problem link - https://leetcode.com/problems/minimum-distance-to-the-target-element/description/?envType=problem-list-v2&envId=array

let getMinDistance = function(nums, target, start) {
    // find length of `nums` array
    const n = nums.length;

    // step 1 - iterate on `nums` array
    let minAbs = Number.MAX_VALUE;
    for(let i=0; i<n; i++){
        // step 2 - check if target exist 
        if(nums[i] === target){
            // step 3 - find absolute value of (i - start) 
            let currAbsVal = Math.abs(i - start);
            
            // step 4 - update minimum absolute value
            if(currAbsVal < minAbs){
                minAbs = currAbsVal;
            }
        }
    }

    // step 5 - return minimum absolute value
    return minAbs;
};

// const nums = [1,2,3,4,5], target = 5, start = 3;

// const nums = [1], target = 1, start = 0;

// const nums = [1,1,1,1,1,1,1,1,1,1], target = 1, start = 0;

const nums = [1,1,1,1,1,1,1,1,1,1], target = 1, start = 9;
console.log(getMinDistance(nums, target, start));