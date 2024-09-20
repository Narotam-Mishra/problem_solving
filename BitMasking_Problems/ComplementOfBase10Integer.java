
// Problem link : https://leetcode.com/problems/complement-of-base-10-integer/?envType=problem-list-v2&envId=bit-manipulation

package BitMasking_Problems;

public class ComplementOfBase10Integer {
    public static int bitwiseComplement(int n) {
        // step 1: find the bit length of the number
        int bitLength = Integer.toBinaryString(n).length();

        // step 2: create a mask of the same length with all bits set to 1
        int bitMask = (1 << bitLength) - 1;

        // step 3: XOR the number with the mask to get the complement
        return bitMask ^ n;
    }

    public static void main(String[] args) {
        // int num = 5;

        // int num = 7;

        int num = 10;
        System.out.println(bitwiseComplement(num));
    }
}
