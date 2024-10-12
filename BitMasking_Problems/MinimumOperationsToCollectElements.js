
// Problem link : https://leetcode.com/problems/minimum-operations-to-collect-elements/description/?envType=problem-list-v2&envId=bit-manipulation&status=TO_DO&difficulty=EASY

let minOperations = function(nums, k) {
    // initialize a set to keep track of collected elements from 1 to k
    let collection = new Set();
    let minOps = 0;

    // traverse the array from the last element to the first
    for(let i=nums.length-1; i>=0; i--){
        // perform one operation (remove the last element)
        minOps++;

        // if the current element is between 1 and k, 
        // add it to the collected set
        if(nums[i] >= 1 && nums[i] <= k){
            collection.add(nums[i]);
        }

        // if we've collected all elements from 1 to k, we can stop
        if(collection.size === k){
            break;
        }
    }

    // return the number of operations performed
    return minOps;
};

let nums = [3,1,5,4,2], k = 2;

// let nums = [3,1,5,4,2], k = 5;
console.log(minOperations(nums, k));
