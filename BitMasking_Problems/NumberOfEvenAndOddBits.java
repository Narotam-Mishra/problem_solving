
// Problem link : https://leetcode.com/problems/number-of-even-and-odd-bits/description/?envType=problem-list-v2&envId=bit-manipulation&status=TO_DO&difficulty=EASY

package BitMasking_Problems;

import java.util.Arrays;

public class NumberOfEvenAndOddBits {
    public static int[] evenOddBit(int n) {
        int curBit = 0, pos = 0;

        // initialize counters for even and odd positions
        int oddCnt = 0, evenCnt = 0;

        // iterate through all bits of n until n becomes zero
        while (n > 0) {
            // isolate the least significant bit (LSB) by performing bitwise AND with 1
            curBit = n & 1;

            // if the current bit is 1, check its position and update the respective counter
            if (curBit == 1) {
                if ((pos & 1) == 1) {
                    // if position is odd (pos & 1 equals 1), increment oddCnt
                    oddCnt++;
                } else {
                    // if position is even (pos & 1 equals 0), increment evenCnt
                    evenCnt++;
                }
            }
            // right-shift n to process the next bit in the next iteration
            n = n >> 1;

            // increment the bit position counter
            pos++;
        }

        // return the counts of 1's at even and odd positions
        return new int[] { evenCnt, oddCnt };
    }

    public static void main(String[] args) {
        // int n = 50;

        int n = 2;
        int[] res = evenOddBit(n);
        System.out.println(Arrays.toString(res));
    }
}