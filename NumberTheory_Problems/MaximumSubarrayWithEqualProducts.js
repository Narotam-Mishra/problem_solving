
// Problem link - https://leetcode.com/problems/maximum-subarray-with-equal-products/description/?envType=problem-list-v2&envId=number-theory

// utility function to finf GCD of two numbers
function gcd(a, b){
    while(b !== 0){
        const temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// utility function to find LCM of two numbers
function lcm(a, b){
    return (a * b) / gcd(a, b);
}

let maxLength = function (nums) {
  // store length of longest product equivalent subarray in `maxLen`
  let maxLen = 0;
  const n = nums.length;

  // step 1 - iterate over all possible starting indices
  for (let i = 0; i < n; i++) {
    let currGCD = nums[i];
    let currLCM = nums[i];
    let currProd = nums[i];

    // step 2 - iterate on all possible subarray from i to j
    for (let j = i; j < n; j++) {
      if (j > i) {
        // update product
        currProd *= nums[j];

        // step 3 - prevent overflow
        if (currProd > 1e18) break;

        // step 4 - update GCD and LCM
        currGCD = gcd(currGCD, nums[j]);
        currLCM = lcm(currLCM, nums[j]);
      }

      // step 5 - check if subarray is product equivalent
      if (currProd === currGCD * currLCM) {
        maxLen = Math.max(maxLen, j - i + 1);
      }
    }
  }

  //   step 6 - return maxLen
  return maxLen
};

// const nums = [1,2,1,2,1,1,1];

// const nums = [2, 3, 4, 5, 6];

const nums = [1,2,3,1,4,5,1];
console.log(maxLength(nums));
