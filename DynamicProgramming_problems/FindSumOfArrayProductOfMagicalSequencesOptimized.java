
// Problem link - https://leetcode.com/problems/find-sum-of-array-product-of-magical-sequences/?envType=daily-question&envId=2025-10-12

package DynamicProgramming_problems;

import java.util.*;

class FindSumOfArrayProductOfMagicalSequencesOptimized {
    private static final int MOD = 1000000007;
    private static int N, K;
    
    // stores factorials for nCr calculation
    private static long[] fact;
    
    // stores modular multiplicative inverse of factorials
    private static long[] invFact;   
    
    // use HashMap with custom Key class for memoization
    // Java doesn't have tuple, so we create a cache key class
    private static Map<CacheKey, Long> cache;
    
    // custom class to use as HashMap key (replaces tuple in C++)
    // MUST override equals() and hashCode() for HashMap to work correctly
    private static class CacheKey {
        long binarySum;
        int m, k, i;
        
        CacheKey(long binarySum, int m, int k, int i) {
            this.binarySum = binarySum;
            this.m = m;
            this.k = k;
            this.i = i;
        }
        
        // Override equals for proper HashMap key comparison
        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof CacheKey)) return false;
            CacheKey key = (CacheKey) o;
            return binarySum == key.binarySum && 
                   m == key.m && 
                   k == key.k && 
                   i == key.i;
        }
        
        // Override hashCode for proper HashMap key hashing
        @Override
        public int hashCode() {
            return Objects.hash(binarySum, m, k, i);
        }
    }

    // Compute (a^b) % mod using binary exponentiation
    // Time Complexity: O(log b)
    private static long fastPower(long a, long b) {
        if (b == 0) return 1;
        
        // Divide and conquer: a^b = (a^(b/2))^2
        long halfPower = fastPower(a, b / 2);
        long res = (halfPower * halfPower) % MOD;
        
        // If b is odd, multiply by a one more time
        if (b % 2 == 1) {
            res = (res * a) % MOD;
        }
        return res;
    }
    
    // Compute nCr % mod using precomputed factorials
    // nCr = n! / (r! * (n-r)!)
    private static long nCr(int n, int r) {
        return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
    }
    
    // Core recursive function with memoization
    // Parameters:
    //   binarySum: accumulated sum of powers of 2
    //   m: remaining positions to fill in sequence
    //   k: remaining set bits needed
    //   i: current index in nums array
    private static long computeRec(long binarySum, int m, int k, int i, int[] nums) {
        // Create unique key for memoization
        CacheKey key = new CacheKey(binarySum, m, k, i);
        
        if (cache.containsKey(key)) {
            return cache.get(key);
        }
        
        // Base case 1: Sequence is complete
        // Check if we used exactly m positions and binarySum has exactly k set bits
        if (m == 0 && Long.bitCount(binarySum) == k) {
            return 1; // Valid magical sequence found
        }
        
        // Base case 2: Invalid state
        if (m == 0 || i >= N) {
            return 0;
        }
        
        long totalSum = 0;
        
        // Option 1: Skip current index i
        // Shift binarySum right and update k based on LSB
        totalSum = (totalSum + computeRec((binarySum >> 1), m, k - (int)(binarySum & 1), i + 1, nums)) % MOD;
        
        // Option 2: Use index i multiple times (frq = 1 to m)
        for (int frq = 1; frq <= m; frq++) {
            // Add frq to binarySum (each occurrence contributes 2^i)
            long newBinarySum = binarySum + frq;
            
            // Recursively solve for remaining positions
            long prod = computeRec((newBinarySum >> 1), m - frq, k - (int)(newBinarySum & 1), i + 1, nums) % MOD;
            
            // Multiply by nums[i]^frq
            prod = (fastPower(nums[i], frq) % MOD * prod % MOD) % MOD;
            
            // Multiply by nCr(m, frq) for arrangement count
            prod = (prod * nCr(m, frq)) % MOD;
            
            totalSum = (totalSum + prod) % MOD;
        }
        
        // Store result in cache and return
        cache.put(key, totalSum);
        return totalSum;
    }
    
    public static int magicalSum(int m, int k, int[] nums) {
        // initialize instance variables
        K = k;
        N = nums.length;
        cache = new HashMap<>();
        
        // precompute factorials for nCr calculations
        fact = new long[m + 1];
        invFact = new long[m + 1];
        fact[0] = 1;
        invFact[0] = 1;
        
        // compute fact[i] = i! % mod
        // FIX: Start from 1, not 2 (we need fact[1] = 1)
        for (int i = 1; i <= m; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        
        // compute modular multiplicative inverse using Fermat's Little Theorem
        for (int i = 0; i <= m; i++) {
            invFact[i] = fastPower(fact[i], MOD - 2);
        }
        
        // start recursion from index 0 with empty sequence
        return (int)(computeRec(0, m, k, 0, nums) % MOD);
    }

    public static void main(String[] args) {
        // Test case 1
        int[] nums = {5,4,3,2,1};
        int m = 2, k = 2;

        // Test case 2
        // int[] nums = {28};
        // int m = 1, k = 1;

        // Test case 3
        // int[] nums = {1,10,100,10000,1000000};
        // int m = 5, k = 5;
        System.out.println("Result: " + magicalSum(m, k, nums));
    }
}