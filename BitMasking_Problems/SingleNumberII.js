
// Problem link : https://leetcode.com/problems/single-number-ii/description/

let singleNumber = function(nums) {
    let res = 0
    let mask, sum;

    // iterate through each 32-bit positions
    for(let i=0; i<32; i++){
        // create mask where i-th bit is set
        mask = (1 << i);
        sum = 0;
        // sum will keep track of the count of 1s at the i-th bit position

        // iterate through all numbers in array
        for(let num of nums){
            // check if the i-th bit is set in the current number 'num'
            if((num & mask) !==0){
                // increment sum
                sum++;
            }
        }

        // after couting, check if the sum is not divisible by 3
        // it means that the unique number has the i-th bit set
        if(sum % 3 !== 0){
            // set the i-th bit in the result
            res = res | mask;
        }
    }
    return res;
};

let nums = [2, 2, 3, 2]
console.log(singleNumber(nums));
