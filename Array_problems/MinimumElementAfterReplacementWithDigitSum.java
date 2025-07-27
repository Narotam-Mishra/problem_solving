
// Problem link - https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/?envType=problem-list-v2&envId=array

package Array_problems;

public class MinimumElementAfterReplacementWithDigitSum {
    private static int findDigitsSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num = num / 10;
        }
        return sum;
    }

    public static int minElement(int[] nums) {
        // store minimum number after replacement in `minNum`
        int minNum = Integer.MAX_VALUE;

        // step 1 - iterate on `nums` array
        for (int num : nums) {
            // step 2 - find digit sum if it is grater than 9
            if (num > 9) {
                int s = findDigitsSum(num);
                // step 3 - update minimum number
                minNum = Math.min(minNum, s);
            } else {
                // update minimum number
                minNum = Math.min(minNum, num);
            }
        }

        // step 4 - return minimum number `minNum` after replacement
        return minNum;
    }

    public static void main(String[] args) {
        // int[] nums = {10,12,13,13};

        // int[] nums = {1,2,3,4};

        int[] nums = {999,19,199};
        System.out.println(minElement(nums));
    }
}
