
// Problem link - https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/description/?envType=daily-question&envId=2025-10-15

let maxIncreasingSubarrays = function (nums) {
  // find size of `nums` list
  const n = nums.length;

  // currRun: length of current strictly increasing sequence
  // prevRun: length of previous strictly increasing sequence
  let currRun = 1,
    prevRun = 0;

  // step 1 - iterate on each number of `nums`
  let k = 0;
  for (let i = 1; i < n; i++) {
    // step 2 - check if current number is greater than previous number
    if (nums[i] > nums[i - 1]) {
      // extend current increasing run
      currRun++;
    } else {
      // step 3 - current run breaks, save it as previous and reset current
      prevRun = currRun;
      currRun = 1;
    }

    // step 4 - case 1 : two adjacent subarrays of length k within the
    // current run so, we can split currRun into two equal or nearly equal parts
    k = Math.max(k, Math.floor(currRun / 2));

    // step 5 - case 2 : one subarray at end of previous run, one at
    // start of current run so, the maximum k is limited by the shorter of the two runs
    k = Math.max(k, Math.min(currRun, prevRun));
  }

  // step 6 - return final value of `k`
  return k;
};

// const nums = [2,5,7,8,9,2,3,4,3,1];

const nums = [1,2,3,4,4,4,4,5,6,7];
console.log(maxIncreasingSubarrays(nums));