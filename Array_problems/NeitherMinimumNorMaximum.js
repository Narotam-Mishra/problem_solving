
// Problem link - https://leetcode.com/problems/third-maximum-number/description/?envType=problem-list-v2&envId=array

let findNonMinOrMax = function(nums) {
    // step 1 - find minimum number in `nums`
    let minNum = Math.min(...nums);

    // step 2 - find maximum number in `nums`
    let maxNum = Math.max(...nums);

    // step 3 - iterate on nums
    for(let num of nums){
        // step 4 - compare numbers `num` from minimum and maximum number that are not equal
        if(num !== minNum && num !== maxNum){
            // step 5 - return neither maximum nor minimum number
            return num;
        }
    }

    // step 6 - if no number found, return -1
    return -1;
};

// const nums = [3,2,1,4];

// const nums = [1,2];

const nums = [2,1,3];
console.log(findNonMinOrMax(nums));