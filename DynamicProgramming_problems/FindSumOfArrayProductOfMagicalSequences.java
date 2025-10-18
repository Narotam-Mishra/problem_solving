
// Problem link - https://leetcode.com/problems/find-sum-of-array-product-of-magical-sequences/description/

package DynamicProgramming_problems;

import java.util.*;

public class FindSumOfArrayProductOfMagicalSequences {
    private static final int MOD = 1000000007;
    private static int N, M, K;

    // cache to store previously computed results
    // key format: "count-sum" where count is current sequence length and sum is the current bit sum
    private static Map<String, Long> cache;
    
    // recursive helper method to calculate sum of products for all magical sequences
    private static long solveRec(int count, long sum, int[] nums){
        // step 1 - base case: we've selected M indices
        if (count == M) {
            // step 1.1 - check if the binary representation of sum has exactly K set bits
            if (Long.bitCount(sum) == K) {
                // valid magical sequence found, contribute 1 to the product chain
                return 1; 
            }
            // invalid sequence, contribute 0
            return 0; 
        }
        
        // step 2 - create unique key for memoization based on current state
        String key = count + "-" + sum;
        
        // step 3 - return cached result if this state was computed before
        if (cache.containsKey(key)) {
            return cache.get(key);
        }
        
        // step 4 - try adding each index from 0 to N-1 to the current sequence
        long totalSum = 0;
        for (int i = 0; i < N; i++) {
            // step 4.1 - add 2^i to the current sum (representing selection of index i)
            long newSum = sum + (1L << i);
            
            // step 4.2 - recursively calculate sum for sequences that include index i at this position
            // multiply by nums[i] as this index contributes nums[i] to the product
            long prod = (nums[i] * solveRec(count + 1, newSum, nums)) % MOD;
            
            // step 4.3 - add this contribution to the total sum
            totalSum = (totalSum + prod) % MOD;
        }

        // step 5 - cache the result before returning
        cache.put(key, totalSum);
        return totalSum;
    }
    public static int magicalSum(int m, int k, int[] nums) {
        M = m;
        K = k;
        N = nums.length;
        cache = new HashMap<>();

        // solve the problem recursively
        return (int)(solveRec(0, 0, nums) % MOD);
    }

    public static void main(String[] args) {
        // int[] nums = {5,4,3,2,1};
        // int m = 2, k = 2;

        // int[] nums = {28};
        // int m = 1, k = 1;

        int[] nums = {1,10,100,10000,1000000};
        int m = 5, k = 5;
        System.out.println(magicalSum(m, k, nums));
    }
}   