
// Problem link - https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/description/?envType=daily-question&envId=2026-02-01

let minimumCost = function(nums) {
    const n = nums.length;

    // keep track of minimum cost `minCost`
    let minCost = nums[0];

    // step 1 - keep track of first and second minimum
    let firstMin = Infinity;
    let secondMin = Infinity;

    // step 2 - iterate of remaining part of array and compute
    for(let i=1; i<n; i++){
        if(nums[i] < firstMin){
            secondMin = firstMin;
            firstMin = nums[i];
        }else if(nums[i] < secondMin){
            secondMin = nums[i];
        }
    }

    // step 3 - return the minimum possible sum
    return minCost + firstMin + secondMin;
};

// const nums = [1,2,3,12];

// const nums = [5,4,3];

const nums = [10,3,1,1];
console.log(minimumCost(nums));