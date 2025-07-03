
// Problem link - https://leetcode.com/problems/decompress-run-length-encoded-list/description/?envType=problem-list-v2&envId=array

let decompressRLElist = function(nums) {
    // store resultant decompressed list in `res`
    const res = [];

    // step 1 - iterate on input array `nums`
    for(let i=0; i<nums.length; i+=2){
        // step 2 - extraxt frq and value
        let frq = nums[i];
        let val = nums[i+1];

        // step 3 - fill the value in `res`
        while(frq > 0){
            res.push(val);
            frq--;
        }
    }

    // step 4 - return resultant array `res`
    return res;
};

// const nums = [1,2,3,4];

const nums = [1,1,2,3];
console.log(decompressRLElist(nums));