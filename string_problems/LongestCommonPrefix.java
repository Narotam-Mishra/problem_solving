
// Problem link : https://leetcode.com/problems/longest-common-prefix/description/

package string_problems;

public class LongestCommonPrefix {

    public static String longestCommonPrefix(String[] strs) {
        // corner case: if the array is empty, return ""
        if (strs.length == 0)
            return "";

        // start with the first string as the prefix
        String prefix = strs[0];

        // iterate on the string array
        for (int i = 1; i < strs.length; i++) {
            while (!strs[i].startsWith(prefix)) {
                // shorten the prefix until it's a prefix of strs[i]
                prefix = prefix.substring(0, prefix.length() - 1);
            }

            // if prefix becomes empty, return ""
            if (prefix.isEmpty())
                return "";
        }
        return prefix;
    }

    public static void main(String[] args) {
        // String[] strs = {"flower","flow","flight"};

        String[] strs = {"dog","racecar","car"};
        System.out.println(longestCommonPrefix(strs));
    }
}
