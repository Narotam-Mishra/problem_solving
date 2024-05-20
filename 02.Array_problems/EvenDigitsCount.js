
// Problem link - https://leetcode.com/problems/find-numbers-with-even-number-of-digits/d%C4%81escription/

let findNumbers = function(nums) {
    let count = 0;
    for(let i=0; i<nums.length; i++){
        let len = nums[i].toString().length;
        if(len%2 === 0){
            count++;
        }
    }
    return count;
};