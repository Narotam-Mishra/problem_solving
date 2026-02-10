
// Problem link - https://leetcode.com/problems/longest-balanced-subarray-i/?envType=daily-question&envId=2026-02-10

let longestBalanced = function(nums) {
    // find length of `nums`
    const n = nums.length;

    // keep track of longest balanced subarray
    let maxLen = 0;

    // step 1 - iterate on each num of `nums`
    for(let i=0; i<n; i++){
        const oddNums = new Set();
        const evenNums = new Set();

        // step 2 - iterate on each subarray
        for(let j=i; j<n; j++){
            // step 3 - store even and odd numbers
            if(nums[j] % 2 == 0){
                evenNums.add(nums[j]);
            }else{
                oddNums.add(nums[j]);
            }

            // step 4 - check if the size size of odd and even numbers are
            // same or not
            if(evenNums.size == oddNums.size){
                maxLen = Math.max(maxLen, j-i+1);
            }
        }
    }

    // step 5 - return longest balanced subarray length
    return maxLen;
};

// const nums = [2,5,4,3];

// const nums = [3,2,2,5,4];

const nums = [1,2,3,2];
console.log(longestBalanced(nums));