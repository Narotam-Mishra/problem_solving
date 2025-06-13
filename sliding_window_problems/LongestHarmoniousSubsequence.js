
// Problem link - https://leetcode.com/problems/longest-harmonious-subsequence/description/?envType=problem-list-v2&envId=sliding-window

let findLHS = function(nums) {
    // step 1 - count frquencies
    let frqMap = {};
    for(let num of nums){
        frqMap[num] = (frqMap[num] || 0) + 1;
    }

    // step 2 - iterate on each number of `nums`
    let maxLength = 0;
    for(let num of nums){
        // step 3 - check if adjacent pairs exist
        if(frqMap[num + 1]){
            // step 4 - calculate length of harmonious subsequence
            let currLen = frqMap[num] + frqMap[num +1];

            // step 5 - update maximum length
            maxLength = Math.max(maxLength, currLen);
        }
    }

    // step 6 - return maximun subsequence length `maxLength`
    return maxLength;
};

// const nums = [1,3,2,2,5,2,3,7];

// const nums = [1,2,3,4];

const nums = [1,1,1,1];
console.log(findLHS(nums));
