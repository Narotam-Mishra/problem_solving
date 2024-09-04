
// Problem link : https://leetcode.com/problems/convert-a-number-to-hexadecimal/description/?envType=problem-list-v2&envId=bit-manipulation

package BitMasking_Problems;

public class ConvertNumberToHexaDecimal {
    public static String toHex(int num) {
        // handle the edge case for 0
        if(num == 0) return "0";

        // handle negative numbers using two's complement
        // convert to hexadecimal string
        return Integer.toHexString(num);
    }

    public static void main(String[] args) {
        int num = 26;

        // int num = -1;
        System.out.println(toHex(num));
    }
}