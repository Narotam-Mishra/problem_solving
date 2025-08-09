
// Problem link - https://leetcode.com/problems/min-max-game/description/?envType=problem-list-v2&envId=array

let minMaxGame = function(nums) {
    // step 1 - repeat the process until `nums` array length greater than 1
    while(nums.length > 1){
        const n = nums.length;

        // step 2 - since length is always power of 2, division is exact
        const newLen = n / 2;

        // step 3 - process each pair and build new array as per given condition
        for(let i=0; i<newLen; i++){
            // first element of pair
            const leftNum = nums[2*i];

            // second element of pair
            const rightNum = nums[2*i+1];

            // step 4 - apply min-max rule based on index
            if(i % 2 === 0){
                nums[i] = Math.min(leftNum, rightNum);
            }else{
                nums[i] = Math.max(leftNum, rightNum);
            }
        }

        // step 5 - shrink array by its new length `newLen`
        nums.length = newLen;
    }

    // step 6 - return last number 
    return nums[0];
};

// const nums = [1,3,5,2,4,8,2,2];

const nums = [3];
console.log(minMaxGame(nums));