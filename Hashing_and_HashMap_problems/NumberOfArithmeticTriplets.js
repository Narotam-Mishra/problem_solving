
// Problem link : https://leetcode.com/problems/number-of-arithmetic-triplets/description/?envType=problem-list-v2&envId=hash-table

let arithmeticTriplets = function(nums, diff) {
    // step 1 - store nums array in set for quick lookup
    let numSet = new Set(nums);
    let count = 0;

    // step 2 - iterate through nums and check for arithmetic triplets
    for(let num of nums){
        if(numSet.has(num + diff) && numSet.has(num + 2 * diff)){
            // found valid triplet, increment count
            count++;
        }
    }

    // step 3 - return required count
    return count;
};

// const nums = [0,1,4,6,7,10], diff = 3;

const nums = [4,5,6,7,8,9], diff = 2;
console.log(arithmeticTriplets(nums, diff));
