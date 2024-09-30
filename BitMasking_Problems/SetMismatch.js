
// Problem link :- https://leetcode.com/problems/set-mismatch/description/?envType=problem-list-v2&envId=bit-manipulation

let findErrorNums = function(nums) {
    // sort the array to make it easier to spot the duplicate
    nums.sort((a, b) => a - b);

    // initialize with default values
    let duplicateNum = -1, missingNum = -1;
    let n = nums.length;

    // iterate through the sorted array to find the duplicate number
    for(let i=1; i<nums.length; i++){
        if(nums[i-1] === nums[i]){
            // find duplicate
            duplicateNum = nums[i];
        }
    }

    // calculate the expected sum of numbers from 1 to n
    let expSum = (n * (n + 1)) / 2;

    // calculate the actual sum of the array with the duplicate
    let actSum = nums.reduce((a, b) => a + b, 0);

    // Missing number = expected sum - (actual sum - duplicate number)
    missingNum = expSum - (actSum - duplicateNum);
    return [duplicateNum, missingNum];
};

// let nums = [1, 2, 2, 4]

// let nums = [1, 1]

let nums = [2, 2]
console.log(findErrorNums(nums));
