
// Problem link - https://leetcode.com/problems/maximum-subarray-with-equal-products/?envType=problem-list-v2&envId=number-theory

package NumberTheory_Problems;

public class MaximumSubarrayWithEqualProducts {
    // utility method to find GCD of two numbers
    private static long gcd(long a, long b){
        while(b != 0){
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    // utility method to find LCM of two numbers
    private static long lcm(long a, long b){
        return (a * b) / gcd(a, b);
    }

    public static int maxLength(int[] nums) {
        // store length of longest product equivalent subarray in `maxLen`
        int maxLen = 0;
        int n = nums.length;

        // step 1 - loop through all subarrays
        for (int i = 0; i < n; i++) {
            long currGCD = nums[i];
            long currLCM = nums[i];
            long currProd = nums[i];

            // step 2 - iterate on each subarray starting from index `i`
            for (int j = i; j < n; j++) {
                if (j > i) {
                    currProd *= nums[j];

                    // step 3 - to prevent overflow, break if product is too large
                    if(currProd > 1e18) break;

                    // step 4 - update GCD and LCM
                    currGCD = gcd(currGCD, nums[j]);
                    currLCM = lcm(currLCM, nums[j]);
                }

                // step 5 - check the product equivalent condition
                if(currProd == currGCD * currLCM){
                    maxLen = Math.max(maxLen, j - i + 1);
                }
            }
        }

        // step 6 - return maxLen
        return maxLen;
    }

    public static void main(String[] args) {
        // int[] nums = {1,2,1,2,1,1,1};

        // int[] nums = {2,3,4,5,6};

        int[] nums = {1,2,3,1,4,5,1};
        System.out.println(maxLength(nums));
    }
}