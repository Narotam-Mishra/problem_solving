
// Problem link :- https://leetcode.com/problems/total-hamming-distance/description/?envType=problem-list-v2&envId=bit-manipulation

let totalHammingDistance = function(nums) {
    let hSum = 0;
    const n = nums.length;

    // iterate over each bit position (0 to 31)
    for(let i=0; i<32; i++){
        let ones = 0;

        // count how many numbers have a 1 at bit position i
        for(let num of nums){
            ones += (num >> i) & 1;
        }

        // number of zeros at this bit position
        const zeros = n - ones;

        // contribution of this bit position to total Hamming distance
        hSum += (ones * zeros);
    }
    return hSum;
};

let nums = [4, 14, 2]
console.log(totalHammingDistance(nums));
