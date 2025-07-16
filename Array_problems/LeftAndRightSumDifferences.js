
// Problem link - https://leetcode.com/problems/left-and-right-sum-differences/description/?envType=problem-list-v2&envId=array

// totalSum = leftSum + rightSum + nums[i]
// hence, rightSum = totalSum - leftSum - nums[i]

let leftRightDifference = function(nums) {
    // store final answer in `answer` array
    const answer = [];

    // step 1 - calculate total sum
    let totalSum = 0;
    for(let num of nums){
        totalSum += num;
    }

    // store left sum in `leftSum`
    let leftSum = 0;

    // step 2 - iterate on nums and calculate difference
    const n = nums.length;
    for(let i=0; i<n; i++){
        // step 3 - calculate right sum 
        let rightSum = totalSum - leftSum - nums[i];

        // step 4 - calculate absolute difference in answer
        answer[i] = Math.abs(leftSum - rightSum);

        // step 5 - calculate left sum
        leftSum += nums[i];
    }

    // step 6 - return `answer` array
    return answer;
};

// const nums = [10,4,8,3];

const nums = [1];
console.log(leftRightDifference(nums));