
// Problem link - https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

// Approach - 1 (Efficient approach using Two Pointers)
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

// Approach - 2 (Efficient approach using object as Map)

let twoSum2 = function (nums, target) {
    let frqMap = {};
  
    for (let i = 0; i < nums.length; i++) {
      if (frqMap[nums[i]]) {
        // if frequency of number exist then increment it
        frqMap[nums[i]]++;
      } else {
        // add new entry
        frqMap[nums[i]] = 1;
      }
    }
  
    const res = [];
    for (let i = 0; i < nums.length; i++) {
      let b = nums[i];
      let a = target - b;
  
      // Check if complement exists in the frequency map
      // If yes, push the index of the current number and the index of the complement
      // make sure we avoid dupllicates
      if (frqMap[a] && (a !== b || frqMap[a] > 1)) {
        // 1-based indexing
        res.push(i+1);
        
        for (let j = i + 1; j < nums.length; j++) {
          if (nums[j] === a) {
            // 1-based indexing
            res.push(j+1);
            return res;
          }
        }
      }
    }
    return res;
  };