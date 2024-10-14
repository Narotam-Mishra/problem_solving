
// Problem link : https://leetcode.com/problems/divide-array-into-equal-pairs/description/?envType=problem-list-v2&envId=bit-manipulation&status=TO_DO&difficulty=EASY

let divideArray = function(nums) {
    // create a hashmap to store the frequency of each number
    let objMap = {};

    // count the occurrences of each number in the array
    for(let num of nums){
        if(objMap[num]){
            objMap[num]++;
        }else{
            objMap[num] = 1;
        }
    }

    // to make pairs, check if each number's frequency is even
    for(let key in objMap){
        // if any number appears an odd number of times, we cannot divide into pairs
        if(objMap[key] & 1) return false
    }
    // all numbers have even counts, so we can divide them into pairs
    return true;
};

// let nums = [3,2,3,2,2,2];

let nums = [1, 2, 3, 4];
console.log(divideArray(nums));
