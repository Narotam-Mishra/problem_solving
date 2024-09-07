
// Problem link : https://leetcode.com/problems/number-complement/?envType=problem-list-v2&envId=bit-manipulation

package BitMasking_Problems;

public class NumberComplement {
    public static int findComplement(int num) {
        // step 1: find the bit length of the number
        int bitLength = Integer.toBinaryString(num).length();

        // step 2: create a mask of the same length with all bits set to 1
        int bitMask = (1 << bitLength) - 1;

        // step 3: XOR the number with the mask to get the complement
        return bitMask ^ num;
    }

    public static void main(String[] args) {
        // int num = 5;

        int num = 1;
        System.out.println(findComplement(num));
    }
}