
// Problem link : https://leetcode.com/problems/reverse-bits/description/?envType=problem-list-v2&envId=bit-manipulation

package BitMasking_Problems;

public class ReverseBits {
    public static int reverseBits(int n) {
        // initialize the result to 0
        int res = 0;

        // loop through each of the 32 bits
        for(int i=0; i<32; i++){
            // shift result to the left by 1 bit to make room for the next bit
            // then extract the least significant bit of n and add it to result
            res = (res << 1) | (n & 1);

            // shift n to the right by 1 bit to process the next bit
            n = n >> 1;
        }
        return res;
    }

    public static void main(String[] args) {
        // int num = 0b00000010100101000001111010011100;

        int num = 0b11111111111111111111111111111101;
        System.out.println(reverseBits(num));
    }
}