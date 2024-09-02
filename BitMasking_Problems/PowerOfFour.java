
// Problem link : https://leetcode.com/problems/power-of-four/

package BitMasking_Problems;

public class PowerOfFour {
    public static boolean isPowerOfFour(int n) {
        boolean exp1 = n > 0 && (n & (n - 1)) == 0;
        boolean exp2 = (n & 0xAAAAAAAA) == 0;
        return exp1 && exp2;
    }

    public static void main(String[] args) {
        int num = 16;
        System.out.println(isPowerOfFour(num));
    }
}