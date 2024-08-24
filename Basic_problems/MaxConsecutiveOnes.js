
// Problem link : https://leetcode.com/problems/max-consecutive-ones/description/

let findMaxConsecutiveOnes = function(nums) {
    let max = counter = 0;

    for(let i=0; i<nums.length; i++) {
        if(nums[i] === 1){
            counter++;
            max = Math.max(max, counter);
        }else{
            counter = 0;
        }
    }
    return max;
};

let nums = [1,1,0,1,1,1];
console.log(findMaxConsecutiveOnes(nums));
