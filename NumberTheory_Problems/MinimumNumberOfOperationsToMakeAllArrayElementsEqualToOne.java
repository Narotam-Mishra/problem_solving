
// Problem link - https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/?envType=daily-question&envId=2025-11-12

package NumberTheory_Problems;

public class MinimumNumberOfOperationsToMakeAllArrayElementsEqualToOne {
    private static int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a%b);
    }

    public static  int minOperations(int[] nums) {
        int n = nums.length;

        // step 1 - count 1's
        int c1 = 0;
        for(int num: nums){
            if(num == 1) c1++;
        }

        if(c1 > 0){
            return n - c1;
        }

        // step 2 - if the array already contains a 1
        // then minimum operations needed is n-1, by propagating 1 to all positions
        for (int num : nums) {
            if (num == 1) {
                // 1 is already present, can propagate it in n-1 steps
                return n - 1;
            }
        }

        // step 3 - no 1 present, find shortest subarray with gcd = 1
        int minLen = n + 1;

        // iterate over all subarrays
        for (int i = 0; i < n; i++) {
            int currGcd = nums[i];

            if (currGcd == 1) {
                // only one element needed, shortest length = 1
                minLen = 1;
                break;
            }

            for (int j = i + 1; j < n; j++) {
                currGcd = gcd(currGcd, nums[j]);
                if(currGcd == 1){
                    int len = j-i+1;
                    if(len < minLen){
                        minLen = len;
                    }
                    break;
                }
            }
        }

        // step 4 - if no subarray found with gcd = 1, return -1
        if(minLen == n+1) return -1;

        // step 5 - calculate operations
        // operations to get one 1 = (min_length - 1)
        // operations to propagate 1 to rest of array = (n - 1)
        return (minLen-1) + (n-1);
    }

    public static void main(String[] args) {
        // int[] nums = {2,6,3,4};

        int[] nums = {2,10,6,14};
        System.out.println(minOperations(nums));
    }
}
