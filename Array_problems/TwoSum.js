
// Problem link - https://leetcode.com/problems/two-sum/description/

// Approach - 1 (Brute Force)

let twoSum = function(nums, target) {
    const res = [];

    for(let i=0; i<=nums.length-2; i++){
        for(let j=i+1; j<=nums.length; j++){
            if(nums[i] + nums[j] === target){
                res.push(i);
                res.push(j);
            }
        }
    }
    return res;
};

// Approach - 2

let twoSum1 = function(nums, target) {

    for(let i=0; i<=nums.length-2; i++){
        for(let j=i+1; j<=nums.length; j++){
            if(nums[i] + nums[j] === target){
                return [i,j];
            }
        }
    }
    return res;
};

// Approach - 3 (Efficient approach using object as map)

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
      res.push(i);
      
      for (let j = i + 1; j < nums.length; j++) {
        if (nums[j] === a) {
          res.push(j);
          return res;
        }
      }
    }
  }
  return res;
};