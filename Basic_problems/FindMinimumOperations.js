
// Problem link - https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/description/

let minimumOperations = function(nums) {
    let count1 = count2 = 0;

    for(let num of nums){
        let remainder = num % 3;
        if(remainder === 1){
            count1++;
        }
        else if (remainder === 2){
            count2++
        } 
    }
    let ans = Math.min(count1, count2) * 2 + Math.abs(count1 - count2);
    return ans;
};

// let nums = [1,2,3,4]

// let nums = [3, 6, 9]

let nums = [1, 1, 1]
console.log(minimumOperations(nums));