
// Problem link - https://leetcode.com/problems/find-the-xor-of-numbers-which-appear-twice/description/?envType=problem-list-v2&envId=bit-manipulation\

let duplicateNumbersXOR = function(nums) {
    // Create a map to store the frequency of each number in the array
    let frqMap = {};

    // traverse through the array to count occurrences of each number
    for(let num of nums){
        if(frqMap[num]){
            frqMap[num]++
        }else{
            frqMap[num] = 1
        }
    }

    // initialize the XOR result as 0
    let xorRes = 0;
    
    // traverse through the frequency map to find numbers that appear twice
    for(let [num, count] of Object.entries(frqMap)){
        // if a number appears exactly twice, XOR it with the result
        if(count === 2){
            xorRes ^= num
        }
    }

    // return xor result 'xorRes'
    return xorRes;
};

// let nums = [1, 2, 1, 3];

let nums = [1, 2, 3];
console.log(duplicateNumbersXOR(nums));
