
// Problem link - https://leetcode.com/problems/combination-sum-iv/

let arr;

function findNumberOfPossibleCombinationsRec(curTarget){
    // Base case: if target become 0 then we will first way
    if(curTarget === 0) return 1;
    
    // Recursive case: recurively calculate number of possible combinations that add up to target
    // f(target) = f(target - arr[i])

    let res = 0;
    for(let i=0; i<arr.length; i++){
        if(curTarget - arr[i] >= 0){
            res += findNumberOfPossibleCombinationsRec(curTarget - arr[i]);
        }
    }
    return res;
}

let combinationSum4 = function(nums, target) {
    arr = nums;
    return findNumberOfPossibleCombinationsRec(target);
};

let nums = [1,2,3]; 
let target = 4
console.log(combinationSum4(nums, target));