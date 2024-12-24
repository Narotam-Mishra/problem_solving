
// Problem link : https://leetcode.com/problems/sum-of-squares-of-special-elements/description/

package Array_problems;

public class SumOfSquaresOfSpecialElements {
    public static int sumOfSquares(int[] nums) {
        // intialize a variable to store the sum of squares
        int ss = 0;

        // calculate length of array
        int n = nums.length;

        // iterate over array elements
        for (int i = 1; i <= Math.sqrt(n); i++) {
            // check for special elements
            if (n % i == 0) {
                // find sum of squares if it is special element
                ss += (nums[i - 1] * nums[i - 1]);

                // n / i is also a divisor, but avoid double counting when i == n / i
                if (i != n / i) {
                    ss += (nums[n / i - 1] * nums[n / i - 1]);
                }
            }
        }

        // return sum of squares `ss`
        return ss;
    }

    public static void main(String[] args) {
        // test case 1
        // int[] nums = {1, 2, 3, 4};

        // test case 2
        int[] nums = {2, 7, 1, 19, 18, 3};
        System.out.println(sumOfSquares(nums)); // 63
    }
}