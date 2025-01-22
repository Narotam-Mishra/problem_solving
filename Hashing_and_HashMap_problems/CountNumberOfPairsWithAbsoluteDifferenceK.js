
// Problem link : https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/description/?envType=problem-list-v2&envId=hash-table

let countKDifference1 = function(nums, k) {
    let count = 0;
    for(let i=0; i<nums.length; i++) {
        for(let j=i+1; j<nums.length; j++) {
            if(Math.abs(nums[i] - nums[j]) === k) {
                count++;
            }
        }
    }
    return count;
};

let countKDifference = function(nums, k) {
    // step 1 - hash map to store the frequency of each number
    const map = new Map();
    let count = 0;

    // step 2 - iterate through each number in the array
    for(let num of nums){
        // 2.1 - check if there exists a number such that num - k = otherNum
        if(map.has(num - k)){
            count += map.get(num - k);
        }

        // 2.2 - check if there exists a number such that num + k = otherNum
        if(map.has(num + k)){
            count += map.get(num + k);
        }

        // step 3 - updated the frequency map with the current number
        map.set(num, (map.get(num) || 0) + 1);
    }

    // step 4 - return the total count of valid pairs
    return count;
};

const nums = [1,2,2,1], k = 1;

// const nums = [1,3], k = 3;

// const nums = [3,2,1,5,4], k = 2;
console.log(countKDifference(nums, k)); 
