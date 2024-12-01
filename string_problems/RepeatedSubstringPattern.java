
// Problem link : https://leetcode.com/problems/repeated-substring-pattern/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

package string_problems;

public class RepeatedSubstringPattern {
    public static boolean repeatedSubstringPattern(String s) {
        // handle edge case:
        if(s.length() == 0){
            return false;
        }

        // step 1 : concatenate the string with itself
        String conStr = s + s;

        // step 2 : remove the first and last characters of the concatenated string
        String modStr = conStr.substring(1, conStr.length() - 1);

        // step 3 : check if the original string is a substring of the modified concatenated string
        return modStr.contains(s);
    }

    public static void main(String[] args) {
        // String str = "aba";

        // String str = "abab";

        String str = "abcabcabcabc";
        System.out.println(repeatedSubstringPattern(str));
    }
}