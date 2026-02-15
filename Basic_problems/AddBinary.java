
// Problem link - https://leetcode.com/problems/add-binary/description/

package Basic_problems;

import java.math.BigInteger;

public class AddBinary {

    // method to convert binary string to BigInteger
    private static BigInteger binaryToDecimal(String binStr){
        return new BigInteger(binStr, 2);
    }

    // method to convert BigInteger to binary string
    private static String decimalToBinary(BigInteger decNum){
        return decNum.toString(2);
    }

    public static String addBinary1(String a, String b) {
        // convert binary strings to BigInteger
        BigInteger decNumA = binaryToDecimal(a);
        BigInteger decNumB = binaryToDecimal(b);

        // sum the BigInteger numbers
        BigInteger sum = decNumA.add(decNumB);

        // convert the sum back to a binary string
        return decimalToBinary(sum);
    }

    public static String addBinary(String a, String b) {
        // find length of both strings `a` and `b`
        int m = a.length() - 1, n = b.length() - 1;

        // keep track of result in `res`
        StringBuilder res = new StringBuilder();

        // keep track of sum and carry
        int sum = 0, carry = 0;

        // step 1 - iterate on both strings
        while (m >= 0 || n >= 0) {
            // assign carry to sum
            sum = carry;

            // step 2 - calculate sum
            if (m >= 0) {
                sum += a.charAt(m) - '0';
                m--;
            }

            if (n >= 0) {
                sum += b.charAt(n) - '0';
                n--;
            }

            // step 3 - store sum into `res`
            res.append((sum % 2 == 0) ? '0' : '1');

            // step 4 - update carry
            carry = (sum > 1) ? 1 : 0;
        }

        // step 5 - check if carry exist in end
        if (carry == 1) {
            // then add to result
            res.append('1');
        }

        // step 6 -  reverse and return final result, `res`
        return res.reverse().toString();
    }

    public static void main(String[] args) {
        String a = "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101";
        String b = "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011";

        System.out.println(addBinary(a, b));
    }
}