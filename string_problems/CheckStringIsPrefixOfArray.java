
// Problem link : https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/

package string_problems;

public class CheckStringIsPrefixOfArray {
    public static boolean isPrefixString(String s, String[] words) {
        // initialize an empty string to build the prefix incrementally
        String prefix = "";

        // step 1 - iterate through the words array
        for(String word : words) {
            // step 2 - add the current word to the prefix
            prefix += word;

            // step 3 - check if the current prefix matches `s`
            if(prefix.equals(s)){
                return true;
            }

            // step 4 - if the prefix length exceeds `s` or diverges from it, return false
            if(prefix.length() > s.length() || !s.startsWith(prefix)){
                return false;
            }
        }

        // step 5 - if we complete the loop and no match is found, return false
        return false;
    }

    public static void main(String[] args) {
        // String s = "iloveleetcode";
        // String[] words = {"i","love","leetcode","apples"};

        String s = "iloveleetcode";
        String[] words = {"apples", "i","love","leetcode"};
        System.out.println(isPrefixString(s, words));
    }
}