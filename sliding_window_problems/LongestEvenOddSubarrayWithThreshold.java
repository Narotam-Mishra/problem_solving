
// Problem link - https://leetcode.com/problems/longest-even-odd-subarray-with-threshold/description/?envType=problem-list-v2&envId=sliding-window

package sliding_window_problems;

public class LongestEvenOddSubarrayWithThreshold {
    public static int longestAlternatingSubarray(int[] nums, int threshold) {
        // store maximum length of alternating subarray in `maxLen`
        int maxLen = 0;
        int n = nums.length;

        // step 1 - iterate through each potential starting position
        for (int l = 0; l < n; l++) {
            // step 2 - check if current position can be a valid start
            if (nums[l] % 2 != 0 || nums[l] > threshold) {
                // skip starting position
                continue;
            }

            // step 3 - found a valid starting position
            int r = l;

            // step 4 - extend the subarray while conditions are met
            while (r < n) {
                // step 5 - check condition 3: current element must be <= threshold
                if (nums[r] > threshold)
                    break;

                // step 6 - check condition 2: alternating parity, except first element
                if (r > l && nums[r] % 2 == nums[r - 1] % 2) {
                    break;
                }

                // step 7 - all conditions satisfied, move to next position
                r++;
            }

            // step 8 - calculate and update maximum length
            maxLen = Math.max(maxLen, r - l);
        }

        // step 9 - return maximum subarray length `maxLen`
        return maxLen;
    }

    public static void main(String[] args) {
        // int[] nums = {3,2,5,4};
        // int threshold = 5;

        // int[] nums = {1,2};
        // int threshold = 2;

        int[] nums = {2,3,4,5};
        int threshold = 4;
        System.out.println(longestAlternatingSubarray(nums, threshold));
    }
}