
// Problem link : https://leetcode.com/problems/sum-of-values-at-indices-with-k-set-bits/description/?envType=problem-list-v2&envId=bit-manipulation&status=TO_DO&difficulty=EASY

// helper function to count the number of set bits (1s) in the binary representation of 'num'.
function countSetBits(num){
    // initialize a counter to store the number of set bits.
    let setBits = 0;

    // loop until 'num' becomes 0.
    while(num > 0){
        // add the least significant bit (LSB) of 'num' to 'setBits'.
        // the bitwise AND operation (num & 1) checks if the LSB is 1.
        setBits += num & 1;

        // right shift 'num' by 1 to move to the next bit.
        num = num >> 1;
    }
    // return the total number of set bits.
    return setBits;
}

let sumIndicesWithKSetBits = function(nums, k) {
    // initialize the sum to 0.
    let s = 0;

    // iterate through each index 'i' in the array 'nums'.
    for(let i=0; i<nums.length; i++){
        // using the helper function to count the number of set bits in index 'i'.
        let setBits = countSetBits(i);
        
        // if the number of set bits in 'i' is exactly 'k', add 'nums[i]' to the sum.
        if(setBits === k){
            s += nums[i];
        }
    }
    // return the total sum after checking all indices.
    return s;
};

// let nums = [5, 10, 1, 5, 2], k = 1;

let nums = [4,3,2,1], k = 2;
console.log(sumIndicesWithKSetBits(nums, k));
