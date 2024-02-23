
// Problem link - https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

let twoSum = function(numbers, target) {
    let s = 0;
    let e = numbers.length-1;

    while(s<e){
        if(numbers[s] + numbers[e] === target){
            return [s+1, e+1]; // 1- based indexing
        }else if(numbers[s] + numbers[e] > target){
            e--;
        }else{
            s++;
        }
    }
};