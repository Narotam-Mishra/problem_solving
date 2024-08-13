
// Problem link : https://leetcode.com/problems/sum-of-all-subset-xor-totals/

let subsetXORSum1 = function(nums) {
    let totalSum = 0
    let n = nums.length

    // iterate over all possible subsets
    for(let i=0; i<(1 << n); i++){
        let currXOR = 0
        // iterate in each number within subset
        for(let j=0; j<n; j++){
            // if ith bit is non-zero then  
            if(i & (1 << j)){
                // then find it XOR
                currXOR ^= nums[j]
            }
        }
        // add the contribution to total sum
        totalSum += currXOR;
    }
    return totalSum;
};

let subsetXORSum = function(nums) {
    let totalSum = 0;
    let n = nums.length;

    for(let num of nums){
        totalSum |= num;
    }

    return (totalSum << n-1)
};

// let nums = [1, 3]

// let nums = [5,1,6]

let nums = [3,4,5,6,7,8]
console.log(subsetXORSum(nums));
