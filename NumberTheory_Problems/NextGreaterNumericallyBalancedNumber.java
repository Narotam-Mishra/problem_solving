
// Problem link - https://leetcode.com/problems/next-greater-numerically-balanced-number/?envType=daily-question&envId=2025-10-24

package NumberTheory_Problems;

public class NextGreaterNumericallyBalancedNumber {
    // utility method to check if number is balanced or not
    private static boolean isBalancedNumber(int num) {
        int[] freq = new int[10];
        while (num > 0) {
            int digit = num % 10;
            freq[digit]++;
            num = num / 10;
        }

        for (int d = 0; d < 10; d++) {
            if (freq[d] > 0 && freq[d] != d) {
                return false;
            }
        }
        return true;
    }

    public static int nextBeautifulNumber(int n) {
        // step 1 - iterate from n+1 to last balanced number in given range
        for (int i = n + 1; i <= 1224444; i++) {

            // step 2 - check if the number is balanced or not
            if (isBalancedNumber(i)) {
                // step 3 - return the balanced number immediately
                return i;
            }
        }

        // otherwise return -1;
        return -1;
    }

    public static void main(String[] args) {
        // int n = 1;

        // int n = 1000;

        int n = 3000;
        System.out.println(nextBeautifulNumber(n));
    }
}