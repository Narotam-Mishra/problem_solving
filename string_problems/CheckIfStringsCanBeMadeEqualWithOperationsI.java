
// Problem link - https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/?envType=problem-list-v2&envId=string

package string_problems;

public class CheckIfStringsCanBeMadeEqualWithOperationsI {
    // utility method to check for match
    private static boolean isMatch(String s1, String s2, int i){
        return (s1.charAt(i) == s2.charAt(i) && s1.charAt(i+2) == s2.charAt(i+2)) || (s1.charAt(i) == s2.charAt(i+2) && s1.charAt(i+2) == s2.charAt(i));
    }

    public static boolean canBeEqual(String s1, String s2) {
        // edge case:
        if(s1.equals(s2)) return true;

        // step 1 - check for match
        return isMatch(s1, s2, 0) && isMatch(s1, s2, 1);
    }

    public static void main(String[] args) {
        // String s1 = "abcd", s2 = "cdab";

        String s1 = "abcd", s2 = "dacb";
        System.out.println(canBeEqual(s1, s2));
    }
}