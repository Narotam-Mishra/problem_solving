
// Problem link - https://leetcode.com/problems/minimize-string-length/description/

package string_problems;

import java.util.*;

public class MinimizeStringLength {
    public static int minimizedStringLength(String s) {
        // step 1 - the minimal length is the number of distinct characters
        Set<Character> uniqueChars = new HashSet<>();
        for(char ch : s.toCharArray()){
            uniqueChars.add(ch);
        }
        return uniqueChars.size();
    }

    public static void main(String[] args) {
        // String s = "aaabc";

        // String s = "cbbd";

        String s = "baadccab";
        System.out.println(minimizedStringLength(s));
    }
}