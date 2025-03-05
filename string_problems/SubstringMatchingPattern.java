
// Problem link - https://leetcode.com/problems/substring-matching-pattern/?envType=problem-list-v2&envId=string

package string_problems;

public class SubstringMatchingPattern {
    public static boolean hasMatch(String s, String p) {
        // step 1 - split the string pattern `p` from '*'
        int startIndex = p.indexOf("*");
        String prefix = p.substring(0, startIndex);
        String suffix = p.substring(startIndex + 1);

        // step 2 - find the first occurrence of prefix in s
        int prefixIndex = s.indexOf(prefix);

        // step 3 - if prefix not found then return false right away
        if(prefixIndex == -1) return false;

        // step 4 - check if suffix exist after prefixIndex
        int suffixIndex = s.indexOf(suffix, prefixIndex + prefix.length());

        // step 5 - suffix must appear after prefix for valid match, otherwise return false
        return suffixIndex != -1;
    }

    public static void main(String[] args) {
        // String s = "leetcode", p = "ee*e";

        // String s = "car", p = "c*v";

        String s = "luck", p = "u*";
        System.out.println(hasMatch(s, p));
    }
}