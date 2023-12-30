
// Problem link - https://leetcode.com/problems/separate-the-digits-in-an-array/description/

// Approach - 1

let separateDigits = function(nums) {
    const res = [];
    for(let i=0; i<nums.length; i++){
        let strNum = nums[i].toString();

        if(strNum.length>1){
            for(let j=0; j<strNum.length; j++){
                res.push(strNum[j]);
            }
        }else{
            res.push(strNum)
        }
    }
    return res;
};

// Approach - 2 (one liner using join() & split())

let separateDigits1 = function(nums) {
    return nums.join('').split('');
};