
// Problem link - https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/description/?envType=daily-question&envId=2025-11-08

let minimumOneBitOperations = function (n) {
  // edge case:
  if (n == 0) return 0;

  // step 1 - precompute f[i] = minimum operations to transform 2^i to 0
  // f[i] = number of operations to convert a number (having only ith set)
  // to 0 formula: f[i] = 2 * f[i-1] + 1
  const f = new Array(31).fill(0);
  // transforming 1 (2^0) to 0 takes 1 operation
  f[0] = 1;
  for (let i = 1; i <= 30; i++) {
    f[i] = 2 * f[i - 1] + 1;
  }

  // step 2 -  process each bit from most significant to least significant (left to right)
  let res = 0,
    sign = 1;

  // iterate through all 31-bits
  for (let i = 30; i >= 0; i--) {
    // step 3 - check if the i-th bit is set in n
    let ithBit = (1 << i) & n;

    // if bit is not set, skip it
    if (ithBit == 0) {
      continue;
    }

    // step 4 - add or subtract f[i] based on alternating sign
    if (sign > 0) {
      res += f[i];
    } else {
      res -= f[i];
    }

    // step 5 - flip sign for next set bit
    sign = sign * -1;
  }

  // step 6 - return minimum operations needed
  return res;
};

// const n = 3;

const n = 6;
console.log(minimumOneBitOperations(n));