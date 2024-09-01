
// Problem link : https://leetcode.com/problems/power-of-two/

package BitMasking_Problems;

public class PowerOfTwo {
    public static boolean isPowerOfTwo(int n) {
        // A power of two has exactly one bit set, 
        // so n > 0 and (n & (n - 1)) should be 0
        boolean res = (n & (n-1)) == 0;
        return (n>0) && res;
    }

    public static void main(String[] args) {
        // int n = 16;

        int n = 3;
        System.out.println(isPowerOfTwo(n));
    }
}