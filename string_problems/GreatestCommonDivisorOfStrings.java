
// Problem link : https://leetcode.com/problems/greatest-common-divisor-of-strings/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

package string_problems;

public class GreatestCommonDivisorOfStrings {

    // helper function to find GCD of two numbers
    private static int findGCD(int a, int b){
        return b == 0 ? a : findGCD(b, a % b);
    }

    public static String gcdOfStrings(String str1, String str2) {
        // step 1: check if concatenated strings are equal
        if (!(str1 + str2).equals(str2 + str1)) {
            return "";
        }

        // step 2: calculate GCD of lengths
        int gcdLen = findGCD(str1.length(), str2.length());

        // step 3: the GCD string is the prefix of either string of length gcdLen
        return str1.substring(0, gcdLen);
    }

    public static void main(String[] args) {
        // String str1 = "ABCABC", str2 = "ABC";

        // String str1 = "ABABAB", str2 = "ABAB";

        String str1 = "LEET", str2 = "CODE";
        System.out.println(gcdOfStrings(str1, str2));
    }
}