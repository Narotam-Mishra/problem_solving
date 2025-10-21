
// Problem link - https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/?envType=daily-question&envId=2025-10-21

package Array_problems;

public class MaximumFrequencyOfElementAfterPerformingOperationsI {
    public static int maxFrequency(int[] nums, int k, int numOperations) {
        // step 1 - find the maximum possible value after operations
        int maxSize = 0;
        for (int num : nums) {
            maxSize = Math.max(maxSize, num);
        }
        maxSize += k;
        
        // step 2 - create frequency array to store count of each value
        int[] freq = new int[maxSize + 1];
        for (int num : nums) {
            freq[num]++;
        }
        
        // step 3 - convert frequency array to prefix sum array
        // this allows O(1) range queries: count in [L, R] = freq[R] - freq[L-1]
        for (int i = 1; i <= maxSize; i++) {
            freq[i] += freq[i - 1];
        }
        
        // step 4 - try every possible target value from 0 to maxSize
        int res = 0;
        for (int target = 0; target <= maxSize; target++) {
            // skip if no element currently has this value
            if (freq[target] == 0) continue;
            
            // step 5 - define the reachable range for this target
            int left = Math.max(0, target - k);
            int right = Math.min(maxSize, target + k);
            
            // step 6 - count total elements in the reachable range using prefix sum
            int totalCount = freq[right] - (left > 0 ? freq[left - 1] : 0);
            
            // step 7 - count elements already at target (no operation needed)
            int targetCount = freq[target] - (target > 0 ? freq[target - 1] : 0);
            
            // step 8 - calculate required operations
            int reqOperations = totalCount - targetCount;
            
            // step 9 - calculate achievable frequency
            int maxFreq = targetCount + Math.min(reqOperations, numOperations);
            
            // update result `res`
            res = Math.max(res, maxFreq);
        }
        
        // step 10 - return final result `res`
        return res;
    }

    public static void main(String[] args) {
        // int[] nums = {1,4,5};
        // int k = 1, numOperations = 2;

        int[] nums = {5,11,20,20};
        int k = 5, numOperations = 1;
        System.out.println(maxFrequency(nums, k, numOperations));
    }
}