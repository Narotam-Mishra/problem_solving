
// Problem link - https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-i/description/?envType=problem-list-v2&envId=array

let minOperations = function(nums, k) {
    // store minimum number of operations needed
    let minOps = 0;

    // step 1 - iterate on input array `nums`
    for(let num of nums){
        // step 2 - increment minimum operation `minOps`
        // if current `num` is less than `k`
        if(num < k){
            minOps++;
        }
    }

    // step 3 - return minimum number of operations needed
    return minOps;
};

// const nums = [2,11,10,1,3], k = 10;

// const nums = [1,1,2,4,9], k = 1;

const nums = [1,1,2,4,9], k = 9;
console.log(minOperations(nums, k));