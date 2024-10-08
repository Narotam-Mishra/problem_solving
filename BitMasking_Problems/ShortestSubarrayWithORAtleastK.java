
// Problem link : https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-i/description/?envType=problem-list-v2&envId=bit-manipulation

package BitMasking_Problems;

public class ShortestSubarrayWithORAtleastK {
    public static int minimumSubarrayLength(int[] nums, int k) {
        int n = nums.length;
        // initialize `minLen` to a value greater than any possible subarray length (n + 1).
        // this will be used to keep track of the minimum subarray length found. 
        int minLen = n + 1;
        
        // to store the cumulative OR value of the current subarray being evaluated.
        int culORVal = 0;

        // outer loop to set the starting index `i` of the subarray
        for(int i=0; i<n; i++){
            // reset cumulative OR value for each new starting index `i`
            culORVal = 0;
            // inner loop to set the ending index `j` of the subarray
            for(int j=i; j<n; j++){
                // update the cumulative OR value with the current element `nums[j]`
                culORVal |= nums[j];
                // check if the cumulative OR value is at least `k`
                if(culORVal >= k){
                    // update the minimum length `minLen` if the current subarray is shorter
                    minLen = Math.min(minLen, j+1-i);
                }
            }
        }
        // if `minLen` is still equal to `n + 1`, no valid subarray was found, so return -1.
        // otherwise, return the minimum length of the special subarray found.
        return minLen == n+1 ? -1 : minLen;
    }

    public static void main(String[] args) {
        // int[] nums = {1, 2, 3};
        // int k = 2;

        // int[] nums = {2, 1, 8};
        // int k = 10;

        int[] nums = {2, 24, 32, 1};
        int k = 22;
        System.out.println(minimumSubarrayLength(nums, k));
    }
}