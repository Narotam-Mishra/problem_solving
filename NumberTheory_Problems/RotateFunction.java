
// Problem link - https://leetcode.com/problems/rotate-function/description/?envType=daily-question&envId=2026-05-01

package NumberTheory_Problems;

public class RotateFunction {
    public int maxRotateFunction(int[] nums) {
        int n = nums.length;

        // step 1 - find total sum
        long totalSum = 0;
        for(int x : nums){
            totalSum += x;
        }

        // step 2 - compute F(0) = 0*nums[0] + 1*nums[1] + ... + (n-1)*nums[n-1]
        long F = 0;
        for(int i=0; i<n; i++){
            F += (long) i * nums[i];
        }

        // initialize max with F(0)
        long maxF = F;

        // step 3 - Use the recurrence to compute F(1), F(2), ..., F(n-1)
        // formula: F(k) = F(k-1) + totalSum - n * nums[n-k]
        for(int k=1; k<n; k++){
            F = F + totalSum - (long) n * nums[n-k];
            maxF = Math.max(maxF, F);
        }

        // step 4
        return (int)maxF;
    }

    public static void main(String[] args) {
        int[] nums = {4,3,2,6};
        RotateFunction obj = new RotateFunction();
        System.out.println(obj.maxRotateFunction(nums));
    }
}
