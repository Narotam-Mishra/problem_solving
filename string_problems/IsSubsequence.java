
// Problem link : https://leetcode.com/problems/is-subsequence/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

package string_problems;

public class IsSubsequence {
    public static boolean isSubsequence(String s, String t) {
        // pointer for source string 's'
        int i = 0;

        // pointer for target string 't'
        int j = 0;

        // traverse through string 't'
        while(j < t.length()){
            // if characters match, move the pointer i for s
            if(i < s.length() && s.charAt(i) == t.charAt(j)){
                i++;
            }

            // move the pointer j for t in each iteration
            j++;
        }
        // if we finished the loop and haven't matched all characters in s
        return i == s.length();
    }

    public static void main(String[] args) {
        String s = "abc", t = "ahbgdc";

        // String s = "axc", t = "ahbgdc";
        System.out.println(isSubsequence(s, t));
    }
}