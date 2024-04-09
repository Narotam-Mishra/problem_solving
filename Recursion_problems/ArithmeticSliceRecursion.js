
// Problem link - https://leetcode.com/problems/arithmetic-slices/description/

// Approach - using Recursion

let arr;

function findNumOfArithmeticSlicesRec(i){
    // Base case1: if ith index is 0 or 1 then there is no Arithmetic slice return 0
    if(i === 0 || i === 1) return 0;

    // Base case2 : if the difference between any two consecutive elements is not the same then return 0
    else if(arr[i] - arr[i-1] !== arr[i-1] - arr[i-2]) return 0;
    else{
        // Recursive case:
        return 1 + findNumOfArithmeticSlicesRec(i-1);
    }
}

let numberOfArithmeticSlices = function(nums) {
    arr = nums;
    let res = 0;
    for(let i=0; i<arr.length; i++){
        res += findNumOfArithmeticSlicesRec(i);
    }
    return res;
};

let nums = [1,2,3,4];
console.log(numberOfArithmeticSlices(nums));