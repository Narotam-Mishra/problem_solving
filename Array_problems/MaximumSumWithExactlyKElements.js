
// Problem link - https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/description/?envType=problem-list-v2&envId=array

let maximizeSum = function(nums, k) {
    // store maximum score in `maxScore`
    let maxScore = 0;

    // step 1 - find maximum value in `nums` for maximum score
    let maxNum = Math.max(...nums);

    // step 2 - perform operation k-times
    while(k > 0){
        // increase score
        maxScore += maxNum;

        // add a new element with a value of `maxNum` + 1
        maxNum++;
        k--;
    }

    // step 3 - return maximum score `maxScore`
    return maxScore;
};

// const nums = [1,2,3,4,5], k = 3;

const nums = [5,5,5], k = 2;
console.log(maximizeSum(nums, k));