
// Problem link - https://leetcode.com/problems/sort-colors/

let sortColors = function (nums) {
  let countZero = 0,
    countOne = 0,
    countTwo = 0;

  for (let i = 0; i < nums.length; i++) {
    if (nums[i] === 0) {
      countZero++;
    } else if (nums[i] === 1) {
      countOne++;
    } else {
      countTwo++;
    }
  }

  let k = 0;
  while (countZero > 0) {
    nums[k++] = 0;
    countZero--;
  }

  while (countOne > 0) {
    nums[k++] = 1;
    countOne--;
  }

  while (countTwo > 0) {
    nums[k++] = 2;
    countTwo--;
  }
};