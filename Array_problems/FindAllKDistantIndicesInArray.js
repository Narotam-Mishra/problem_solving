
// Problem link - https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/description/?envType=problem-list-v2&envId=array

let findKDistantIndices = function(nums, key, k) {
    // find length of input array `nums`
    const n = nums.length;

    // store indices where nums[j] === key
    const keyIndices = [];

    // store final result in `res`
    const res = [];

    // step 1 - find all indices where nums[j] == key
    for(let j=0; j<n; j++){
        if(nums[j] === key){
            keyIndices.push(j);
        }
    }

    // step 2 - for each index i, check if any key is within distance k
    for(let i=0; i<n; i++){
        let isKDistant = false;

        // step 3 - check each key position
        for(let j of keyIndices){
            if(Math.abs(i - j) <= k){
                isKDistant = true;
                break;
            }
        }

        if(isKDistant){
            res.push(i);
        }
    }

    // step 4 - return final result `res`
    return res;
};

const nums = [3,4,9,1,3,9,5], key = 9, k = 1;

// const nums = [2,2,2,2,2], key = 2, k = 2;
console.log(findKDistantIndices(nums, key, k));