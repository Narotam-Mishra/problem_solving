
// Problem link - https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-ii/description/?envType=daily-question&envId=2025-10-22

package Array_problems;

import java.util.*;

public class MaximumFrequencyOfElementAfterPerformingOperationsII {
    public static int maxFrequency(int[] nums, int k, int numOperations) {
        // step 1 - find the maximum possible value after operations
        int maxSize = Arrays.stream(nums).max().getAsInt() + k;

        // step 2 - initialize data structures
        // TreeMap maintains sorted order automatically - acts as difference array
        TreeMap<Integer, Integer> diff = new TreeMap<>();
        
        // frequency map to track count of each original value in nums
        HashMap<Integer, Integer> freq = new HashMap<>();

        // step 3 - mark reachable ranges for each element
        for(int i = 0; i < nums.length; i++){
            // count frequency of current element (elements already at this value)
            freq.put(nums[i], freq.getOrDefault(nums[i], 0) + 1);

            // calculate the range [l, r] this element can reach with operations
            int l = Math.max(nums[i] - k, 0);           // left boundary (can't go below 0)
            int r = Math.min(nums[i] + k, maxSize);     // right boundary (bounded by maxSize)

            // use difference array technique for O(1) range update
            diff.put(l, diff.getOrDefault(l, 0) + 1);         // increment at range start
            diff.put(r + 1, diff.getOrDefault(r + 1, 0) - 1); // decrement after range end

            // ensure the current value exists as a key in diff map
            // this is important to consider it as a potential target value
            diff.putIfAbsent(nums[i], 0);
        }

        // step 4 - process each possible target value using prefix sum on difference array
        int res = 0;      // result - maximum frequency achievable
        int cumSum = 0;   // cumulative sum to convert difference array to actual counts
        
        for(Map.Entry<Integer, Integer> entry : diff.entrySet()){
            int target = entry.getKey();      // current target value we're evaluating
            int deltaValue = entry.getValue(); // boundary change at this position
            
            // convert difference value to actual count using prefix sum
            // cumSum holds the count from previous position
            int actualCount = deltaValue + cumSum;
            
            // update the map with actual count (for clarity, though not strictly necessary)
            entry.setValue(actualCount);
            
            // Now actualCount represents: total elements that can reach this target
            
            // get count of elements already at target value (no operation needed)
            int targetFreq = freq.getOrDefault(target, 0);

            // calculate how many other elements can reach this target
            // actualCount = total elements that can reach target (including those already there)
            // targetFreq = elements already at target
            // reqOperations = elements that need an operation to reach target
            int reqOperations = actualCount - targetFreq;

            // we can use at most numOperations, so take minimum
            int maxFreq = Math.min(reqOperations, numOperations);

            // total frequency achievable for this target:
            // = elements already at target + elements we modify to reach target
            res = Math.max(res, targetFreq + maxFreq);

            // update cumulative sum for next iteration
            cumSum = actualCount;
        }

        // step 5 - return the maximum frequency found
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