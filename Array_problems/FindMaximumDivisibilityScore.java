
// Problem link - https://leetcode.com/problems/find-the-maximum-divisibility-score/?envType=problem-list-v2&envId=array

package Array_problems;

public class FindMaximumDivisibilityScore {
    public static int maxDivScore(int[] nums, int[] divisors) {
        // step 1 - store maximum divisibility score in `maxScore`
        int maxScore = -1;

        // best divisor (smallest in case of tie)
        int bestDivisor = Integer.MAX_VALUE;

        // step 2 - iterate on each divisor
        for (int i = 0; i < divisors.length; i++) {
            int currDivisor = divisors[i];
            int currScore = 0;

            // step 3 - count how many numbers in nums are divisible by current divisor
            for (int j = 0; j < nums.length; j++) {

                // step 4 - check if number is divisble by divisor
                if (nums[j] % currDivisor == 0) {
                    currScore++;
                }
            }

            // step 5 - update maximum score if
            // case 1 - current score is higher than max score, or
            // case 2 - current score equals max score but current divisor is smaller
            if (currScore > maxScore || currScore == maxScore && currDivisor < bestDivisor) {
                maxScore = currScore;
                bestDivisor = currDivisor;
            }
        }

        // step 6 - return the divisor with the maximum divisibility score
        return bestDivisor;
    }

    public static void main(String[] args) {
        // int[] nums = {2,9,15,50}, divisors = {5,3,7,2};

        // int[] nums = {4,7,9,3,9}, divisors = {5,2,3};

        int[] nums = {20,14,21,10}, divisors = {10,16,20};
        System.out.println(maxDivScore(nums, divisors));
    }
}