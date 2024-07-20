
// /Problem link - https://leetcode.com/problems/number-of-good-pairs/

// Efficient Approach using object as Map
let numIdenticalPairs = function(nums) {
    let count = 0;
    let frq = {}
    for(let i=0; i<nums.length; i++){
        if(frq[nums[i]]){
            count+= frq[nums[i]];
            frq[nums[i]]++;
        }else{
            frq[nums[i]] = 1;
        }
    }
    return count;
};

// Brute Force approach
let numIdenticalPairs1 = function(nums) {
    let count = 0;
    for(let i=0; i<nums.length; i++){
        for(let j=i+1; j<nums.length; j++){
            if(i < j && nums[i] === nums[j]) count++;
        }
    }
    return count;
};

let nums = [1, 2, 3, 1, 1, 3]

// let nums = [1,1,1,1]

// let nums = [1,2,3]
console.log(numIdenticalPairs(nums));