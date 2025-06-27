
// Problem link - https://leetcode.com/problems/third-maximum-number/description/?envType=problem-list-v2&envId=array

let thirdMax = function(nums) {
    // step 1 - use -Infinity to handle negative numbers properly
    let max1 = -Infinity;
    let max2 = -Infinity;
    let max3 = -Infinity;

    // step 2 - iterate on each num of `nums`
    for(let num of nums){

        // step 3 - skip duplicates
        if(num === max3 || num === max2 || num === max1){
            continue;
        }
        // step 4 - if current number is greater than first max
        if(num > max1){
            // shift all values: max1 becomes max2, max2 becomes max3
            max3 = max2;
            max2 = max1;
            max1 = num;
        }

        // step 4 - if current number is between max1 and max2
        else if(num > max2){
            max3 = max2;
            max2 = num;
        }

        // step 5 - if current number is between max2 and max3
        else if(num > max3){
            max3 = num;
        }
    }

    // step 6 - if third maximum exists (not -Infinity), return it, otherwise return first maximum `max1`
    return max3 === -Infinity ? max1 : max3;
};

// const nums = [3,2,1];

// const nums = [1, 2];

const nums = [2,2,3,1];
console.log(thirdMax(nums));