
// Problem link : https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/description/?envType=problem-list-v2&envId=bit-manipulation&status=TO_DO&difficulty=EASY

let minBitwiseArray = function(nums) {
    const ans = [];
    
    for(let num of nums){
        let found = false;
        for(let i=0; i<=num; i++){
            if((i | (i+1)) === num){
                ans.push(i);
                found = true;
                break;
            }
        }

        if(!found){
            ans.push(-1);
        }
    }
    return ans;
};

let nums = [2, 3, 5, 7];
console.log(minBitwiseArray(nums));
