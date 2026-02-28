
// Problem link - https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/description/?envType=daily-question&envId=2026-02-28

package NumberTheory_Problems;

public class ConcatenationOfConsecutiveBinaryNumbers {
    public static int concatenatedBinary1(int n) {
        final int mod = 1_000_000_007;

        // keep track of final result, `res`
        long res = 0;

        // step 1 - iterate on each number from 1 to n
        for(int num=1; num<=n; num++){
            // step 2 - find number of bits to represent this number
            int bits = (int)(Math.log(num) / Math.log(2)) + 1;

            // step 3 - calculate result
            res = ((res << bits) % mod + num) % mod;
        }

        // step 4 - return final result, `res`
        return (int)res;
    }

    public static int concatenatedBinary(int n) {
        int mod = 1_000_000_007;

        // keep track of final result, `res`
        long res = 0;

        int bits = 0;
        // step 1 - iterate on each number from 1 to n
        for (int num = 1; num <= n; num++) {
            // step 2 - check If num is power of 2, increase bit count
            if ((num & (num - 1)) == 0) {
                bits++;
            }

            // step 3 - calculate result
            res = ((res << bits) % mod + num) % mod;
        }

        // step 4 - return final result, `res`
        return (int) res;
    }


    public static void main(String[] args) {
        // int n = 1;

        int n = 12;
        System.out.println(concatenatedBinary(n));
    }
}
