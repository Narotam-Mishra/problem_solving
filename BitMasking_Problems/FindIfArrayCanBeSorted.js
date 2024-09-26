
// Problem link : https://leetcode.com/problems/find-if-array-can-be-sorted/description/?envType=problem-list-v2&envId=bit-manipulation

// utility method to count set bits in binary number
function countSetBits(num) {
  let setBits = 0;

  while (num > 0) {
    setBits += num & 1;
    num = num >> 1;
  }
  return setBits;
}

// utility method to check if array is s rted or not
function isSorted(nums) {
  for (let i = 1; i < nums.length; i++) {
    if (nums[i - 1] > nums[i]) return false;
  }
  return true;
}

let canSortArray = function(nums) {
    const n = nums.length;

     // Outer loop for passes
     for (let i = 0; i < n - 1; i++) {
        // Inner loop for comparisons in each pass
        for (let j = 0; j < n - i - 1; j++) {
            // If adjacent elements can be swapped and are in wrong order
            if (countSetBits(nums[j]) === countSetBits(nums[j + 1]) && nums[j] > nums[j + 1]) {
                // Swap elements
                [nums[j], nums[j + 1]] = [nums[j + 1], nums[j]];
            }
        }
    }

    if(isSorted(nums)){
        return true;
    }else{
        return false;
    }
};

// let nums = [8, 4, 2, 30, 15];

// let nums = [3,16,8,4,2];

// let nums = [1, 2, 3, 4, 5];

// let nums = [136,256,10];

let nums = [20, 16];
console.log(canSortArray(nums));
console.log(canSortArray1(nums));
