
// Problem link : https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/description/?envType=problem-list-v2&envId=bit-manipulation&status=TO_DO&difficulty=EASY

let minBitwiseArray = function(nums) {
    const ans = [];
    
    // iterate through each number in the nums array
    for(let num of nums){
        let found = false;

        // try values for ans[i] starting from 0 and upwards
        for(let i=0; i<=num; i++){

            // check if the condition holds: ans[i] OR (ans[i] + 1) == num
            if((i | (i+1)) === num){
                // if found, push the value of ans[i] into the result array
                ans.push(i);
                found = true;
                // no need to check further, move to the next number
                break;
            }
        }

        // if no valid ans[i] was found, push -1 to indicate it's not possible
        if(!found){
            ans.push(-1);
        }
    }

    // return the constructed ans array
    return ans;
};

// let nums = [2, 3, 5, 7];

let nums = [11, 13, 31];
console.log(minBitwiseArray(nums));
