
// Problem link : https://leetcode.com/problems/binary-number-with-alternating-bits/description/?envType=problem-list-v2&envId=bit-manipulation

package BitMasking_Problems;

public class BinaryNumberWithAlternatingBits {
    public static boolean hasAlternatingBits(int n) {
        // XOR the number with its right-shifted version by 1 bit.
        // this helps to check if adjacent bits are different.
        int x = (n >> 1) ^ n;

        // check if the result of the XOR operation is a sequence of all 1s.
        // adding 1 to such a sequence would give a number with exactly one 1 bit followed by all 0s.
        // if x & (x + 1) results in 0, then the number had alternating bits.
        boolean ans = (x & (x + 1)) == 0;
        return ans;
    }

    public static void main(String[] args) {
        // int num = 5;

        int num = 9;
        System.out.println(hasAlternatingBits(num));
    }
}