
// Problem link - https://leetcode.com/problems/maximum-odd-binary-number/description/?envType=problem-list-v2&envId=string

package string_problems;

public class MaximumOddBinaryNumber {
    public static String maximumOddBinaryNumber(String s) {
        // step 1 - count ones in binary string
        int countOnes = 0;
        for(char ch : s.toCharArray()){
            if(ch == '1'){
                countOnes++;
            }
        }

        // step 2 - find number of zeroes in `s`
        int countZeroes = s.length() - countOnes;

        // step 3 - rearrange binary numbers to from maximum odd binary number
        String res = "1".repeat(countOnes - 1) + "0".repeat(countZeroes) + "1";

        // step 4 - return `res`
        return res;
    }

    public static void main(String[] args) {
        // String s = "010";

        String s = "0101";
        System.out.println(maximumOddBinaryNumber(s));
    }
}
