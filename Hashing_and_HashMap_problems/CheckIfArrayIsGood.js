
// Problem link : https://leetcode.com/problems/check-if-array-is-good/description/?envType=problem-list-v2&envId=hash-table

let isGood1 = function(nums) {
    // step - find length of nums and calculate `n`
    const len = nums.length;

    // the expected highest value in base[n]
    const n = len - 1;

    // step 2 - create frequency map to count occurrences of each number
    const map = {};
    for(let num of nums){
        // if a number is out of the expected range, return false
        if(num < 1 || num > n){
            return false;
        }

        // count occurrences
        map[num] = (map[num] || 0) + 1;
    }

    // step 3 - validate frequency conditions
    for(let i=1; i<n; i++){
        if(map[i] > 1) return false;
    }

    // step 4 - `n` should appear exactly twice
    return map[n] === 2;
};

let isGood = function (nums) {
  // step 1: find the length of the array and calculate `n`
  let n = nums.length - 1;

  // step 2: find the maximum value in the array
  let max = Math.max(...nums);

  // edge case check: `max` must be equal to `n`
  if (max !== n) return false;

  // step 3: calculate frequency of each number in `nums`
  let freqMap = new Array(max + 1).fill(0);
  for (let num of nums) {
    freqMap[num]++;
  }

  // step 4: validate frequency conditions
  for (let i = 1; i < n; i++) {
    if (freqMap[i] !== 1) {
      return false;
    }
  }

  // step 5: `n` should appear exactly twice
  return freqMap[n] === 2;
};

const nums = [2, 1, 3];

// const nums = [1, 3, 3, 2];

// const nums = [1, 1];

// const nums = [3, 4, 4, 1, 2, 1];

// const nums = [14, 2, 2];
console.log(isGood(nums));
