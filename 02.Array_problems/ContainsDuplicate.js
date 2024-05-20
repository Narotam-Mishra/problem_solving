
// Problem link - https://leetcode.com/problems/contains-duplicate/description/

// Approach - 1 (BruteForce)

let containsDuplicate = function(nums) {
    nums.sort((a,b) => a-b);
    for(let i = 0; i < nums.length; i++){
        if(nums[i] === nums[i + 1]){
            return true;
        }
    }
    return false;
};

// Approach - 2 (Efficient using frequency map)

let containsDuplicate1 = function(nums) {
    // prepare frequency map
    const freqMap = {};

    for(let i=0; i<nums.length; i++){
        if(freqMap[nums[i]]){
            // if it is defined, we land here
            freqMap[nums[i]] += 1;
        }else{
            // if it is undefined, we land here
            freqMap[nums[i]] = 1;
        }
    }

    let objVals = Object.values(freqMap);

    for(let i=0; i<objVals.length; i++){
        if(objVals[i] > 1){
            return true;
        }
    }
    return false;
};
