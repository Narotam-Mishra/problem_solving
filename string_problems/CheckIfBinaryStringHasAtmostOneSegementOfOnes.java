
// Problem link - https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/description/

package string_problems;

public class CheckIfBinaryStringHasAtmostOneSegementOfOnes {
    public static boolean checkOnesSegment(String s) {
        return !s.contains("01");
    }
    
    public static void main(String[] args) {
        // String s = "1001";

        String s = "110";
        System.out.println(checkOnesSegment(s));
    }
}