
// Problem link - https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/description/?envType=daily-question&envId=2025-09-05

function makeTheIntegerZero(num1, num2) {
  // Convert to BigInt once; all arithmetic stays in BigInt
  const N1 = BigInt(num1);
  const N2 = BigInt(num2);

  // Helper: count set bits of a non-negative BigInt
  const bitCountBigInt = (n) => {
    let c = 0;
    while (n > 0n) {
      // Add the least significant bit (0 or 1), then shift
      c += Number(n & 1n);
      n >>= 1n;
    }
    return c;
  };

  // Special case: already zero => 0 operations
  if (N1 === 0n) return 0;

  // Try k from 0..60 (standard tight bound for this problem)
  for (let k = 0; k <= 60; k++) {
    const K = BigInt(k);
    const x = N1 - K * N2;      // x must equal sum of k powers of two

    if (x < 0n) continue;       // negative can't be formed by positive powers
    if (K > x) continue;        // need at least k ones to reach x (since min term is 1)

    const bits = bitCountBigInt(x);
    if (bits <= k) {
      // Found the smallest valid k (we scan increasing k)
      return k;
    }
  }

  // No feasible k in 0..60
  return -1;
}

const num1 = 3, num2 = -2;

// const num1 = 5, num2 = 7;
console.log(makeTheIntegerZero(num1, num2));