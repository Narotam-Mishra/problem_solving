
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

    public static String addBinary(String a, String b) {
        // convert binary strings to BigInteger
        BigInteger decNumA = binaryToDecimal(a);
        BigInteger decNumB = binaryToDecimal(b);

        // sum the BigInteger numbers
        BigInteger sum = decNumA.add(decNumB);

        // convert the sum back to a binary string
        return decimalToBinary(sum);
    }

    public static void main(String[] args) {
        String a = "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101";
        String b = "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011";

        System.out.println(addBinary(a, b));
    }
}