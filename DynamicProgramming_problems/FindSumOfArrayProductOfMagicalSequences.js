
// Problem link - https://leetcode.com/problems/find-sum-of-array-product-of-magical-sequences/description/

// Brute Force Approach

const MOD = 1000000007;

/**
 * Counts the number of set bits (1s) in the binary representation of a number
 * @param {number} n - The number to count bits in
 * @return {number} - Count of set bits
 */
function countSetBits(n) {
    let count = 0;
    while (n > 0) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

/**
 * main function to calculate the sum of array products for all magical sequences
 * @param {number} m - Required sequence length
 * @param {number} k - Required number of set bits
 * @param {number[]} nums - Input array
 * @return {number} - Sum of products modulo 10^9 + 7
 */
let magicalSum1 = function(m, k, nums) {
    const N = nums.length;
    const M = m;
    const K = k;
    
    // cache to store previously computed results
    // key format: "count-sum" where count is current sequence length and sum is the current bit sum
    const cache = new Map();
    
    /**
     * recursive helper function to calculate sum of products for all magical sequences
     * @param {number} count - Current length of the sequence being built
     * @param {number} sum - Current sum represented as bits (2^seq[0] + 2^seq[1] + ...)
     * @return {number} - Sum of products for all valid magical sequences from this state
     */
    function solveRec(count, sum) {
        // step 1 - base case: we've selected M indices
        if (count === M) {
            // step 1.1 - check if the binary representation of sum has exactly K set bits
            if (countSetBits(sum) === K) {
                // valid magical sequence found, contribute 1 to the product chain
                return 1; 
            }
            // invalid sequence, contribute 0
            return 0; 
        }
        
        // step 2 - create unique key for memoization based on current state
        const key = `${count}-${sum}`;
        
        // step 3 - return cached result if this state was computed before
        if (cache.has(key)) {
            return cache.get(key);
        }
        
        // step 4 - try adding each index from 0 to N-1 to the current sequence
        let totalSum = 0;
        for (let i = 0; i < N; i++) {
            // step 4.1 - sdd 2^i to the current sum (representing selection of index i)
            const newSum = sum + (1 << i);
            
            // step 4.2 - recursively calculate sum for sequences that include index i at this position
            // multiply by nums[i] as this index contributes nums[i] to the product
            const prod = (nums[i] * solveRec(count + 1, newSum)) % MOD;
            
            // step 4.3 - add this contribution to the total sum
            totalSum = (totalSum + prod) % MOD;
        }
        
        // step 5 - cache the result before returning
        cache.set(key, totalSum);
        return totalSum;
    }
    
    return solveRec(0, 0) % MOD;
}

const mod = 1000000007n; // make mod a BigInt

let magicalSum = function (m, k, nums) {
  const N = nums.length;
  const fact = new Array(m + 1).fill(1n);
  const invFact = new Array(m + 1).fill(1n);
  const cache = new Map();

  // Utility: fast exponentiation (a^b % mod)
  const fastPower = (a, b) => {
    a = BigInt(a);
    b = BigInt(b);
    let res = 1n;
    while (b > 0n) {
      if (b & 1n) res = (res * a) % mod;
      a = (a * a) % mod;
      b >>= 1n;
    }
    return res;
  };

  // Precompute factorials and inverse factorials
  for (let i = 2; i <= m; i++) {
    fact[i] = (fact[i - 1] * BigInt(i)) % mod;
  }

  for (let i = 0; i <= m; i++) {
    invFact[i] = fastPower(fact[i], mod - 2n);
  }

  // Utility: nCr % mod
  const nCr = (n, r) => {
    if (r > n || r < 0) return 0n;
    return (((fact[n] * invFact[r]) % mod) * invFact[n - r]) % mod;
  };

  // Helper: count set bits
  const popcount = (x) => {
    let count = 0;
    while (x > 0) {
      if (x & 1) count++;
      x >>= 1;
    }
    return count;
  };

  // Recursive function with memoization
  const computeRec = (binarySum, m, k, i) => {
    const key = `${binarySum},${m},${k},${i}`;
    if (cache.has(key)) return cache.get(key);

    if (m === 0 && popcount(binarySum) === k) return 1n;
    if (m === 0 || i >= N) return 0n;

    let totalSum = 0n;

    // Skip index i
    totalSum =
      (totalSum +
        computeRec(binarySum >> 1, m, k - (binarySum & 1), i + 1)) %
      mod;

    // Take index i with different frequencies
    for (let frq = 1; frq <= m; frq++) {
      const newBinarySum = binarySum + frq;

      let prod = computeRec(
        newBinarySum >> 1,
        m - frq,
        k - (newBinarySum & 1),
        i + 1
      );

      prod = (fastPower(BigInt(nums[i]), BigInt(frq)) * prod) % mod;
      prod = (prod * nCr(m, frq)) % mod;

      totalSum = (totalSum + prod) % mod;
    }

    cache.set(key, totalSum);
    return totalSum;
  };

  return Number(computeRec(0, m, k, 0) % mod);
};


// const m = 5, k = 5, nums = [1,10,100,10000,1000000];

// const m = 2, k = 2, nums = [5,4,3,2,1];

const m = 1, k = 1, nums = [28];
console.log(magicalSum(m, k, nums));