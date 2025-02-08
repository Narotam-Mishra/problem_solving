
// Problem link : https://leetcode.com/problems/degree-of-an-array/?envType=problem-list-v2&envId=hash-table

// Approach - 1 (with O(n^2) )
let findShortestSubArray1 = function(nums) {
    // step 1 - create a frequency map
    const map = {};

    // step 2 - populate the frequency map
    for(let num of nums){
        map[num] = (map[num] || 0) + 1;
    }
    
    // step 3 - determine the degree of the array
    const degree = Math.max(...Object.values(map));

    // step 4 - find the smallest subarray length
    let minLengthSubArray = Infinity;
    for(let num in map){
        if(map[num] === degree){
            // calculate the length of the subarray
            let subArrLen = nums.lastIndexOf(Number(num)) - nums.indexOf(Number(num)) + 1;
            
            // update the minimum length
            minLengthSubArray = Math.min(minLengthSubArray, subArrLen);
        }
    }

    // step 5 - return the result
    return minLengthSubArray;
};

// Approach - 2 (Optimized with O(n) time complexity)
let findShortestSubArray = function(nums) {
    // step 1 - create maps
    const map = {};  // to store frequency of each array's numbers
    const firstIndex = {}; // stores the first index of each element
    const lastIndex = {}; // stores the lsst index of each element

    // step 2 - build frequency map and track first/last occurrences
    for(let i =0; i < nums.length; i++){
        let num = nums[i];
        map[num] = (map[num] || 0) + 1;

        // track first occurence
        if(firstIndex[num] === undefined){
            firstIndex[num] = i;
        }

        // track last index
        lastIndex[num] = i;
    }

    // step 3 - determine degree of nums
    const degree = Math.max(...Object.values(map));

    // step 4 - find the smallest subarray length
    let minLenSubArray = Infinity;
    for(const num in map){
        if(map[num] === degree){
            const subArrLen = lastIndex[num] - firstIndex[num] + 1;
            minLenSubArray = Math.min(subArrLen, minLenSubArray);
        }
    }

    // step 5 - return the result
    return minLenSubArray;
};

const nums = [1,2,2,3,1];

// const nums = [1,2,2,3,1,4,2];
console.log(findShortestSubArray(nums));
