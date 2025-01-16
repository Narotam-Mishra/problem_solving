
// Problem link : https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/description/?envType=problem-list-v2&envId=hash-table

let getSneakyNumbers1 = function(nums) {
    const frqArr = new Array(103).fill(0);

    for(let num of nums){
        frqArr[num]++;
    }

    const res = [];
    for(let num of new Set(nums)) {
        if(frqArr[num] === 2){
            res.push(num);
        }
    }
    return res;
};

let getSneakyNumbers2 = function(nums) {
    // step 1: initialize result array to store sneaky numbers
    const res = [];

    // step 2: iterate through the list of numbers
    for(let i=0; i<nums.length; i++) {
        // step 3: check for duplicate
        let lastIndex = nums.lastIndexOf(nums[i]);
        if(lastIndex !== -1 && lastIndex !== i){
            // step 4: store sneaky numbers
            res.push(nums[i]);
        }
    }
    // step 5: return resultant `res` list
    return res;
};

let getSneakyNumbers = function(nums) {
    // step 1: initialize result array to store sneaky numbers
    const res = [];

    const seen = new Set();
    // step 2: iterate through the list of numbers
    for(let i=0; i<nums.length; i++) {
        // step 3: check for duplicate
        if(seen.has(nums[i])){
            // step 4: store sneaky numbers
            res.push(nums[i]);
        }else{
            seen.add(nums[i]);
        }
    }
    // step 5: return resultant `res` list
    return res;
};

const nums = [0,3,2,1,3,2];

// const nums = [0,1,1,0];

// const nums = [7,1,5,4,3,4,6,0,9,5,8,2];
console.log(getSneakyNumbers(nums));
