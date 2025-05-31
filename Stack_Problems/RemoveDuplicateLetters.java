
// Problem link - https://leetcode.com/problems/remove-duplicate-letters/description/?envType=problem-list-v2&envId=string

package Stack_Problems;

import java.util.*;

public class RemoveDuplicateLetters {
    public static String removeDuplicateLetters(String s) {
        // step 1 - count frequency of each letter of `s`
        int[] count = new int[26];
        for(char ch : s.toCharArray()){
            count[ch - 'a']++;
        }

        // step 2 - Initialize data structures
        // build resultant string from stack
        Stack<Character> stack = new Stack<>();

        // track which character is already in resultant string
        boolean[] seen = new boolean[26];

        // step 3 - iterate on each character of `s`
        for(char ch : s.toCharArray()){
            // decrease count since we are processing this occurrence
            count[ch - 'a']--;

            // step 4 - if current charcter `ch` already exist in seen then skip it
            if(seen[ch - 'a']){
                continue;
            }

            // current character `char` is smaller than stack top (for lexicographical order)
            // Stack top appears later in string (count > 0)
            // step 5 - this step ensures we always make the lexicographically smallest choice possible
            while (!stack.empty() && stack.peek() > ch && count[stack.peek() - 'a'] > 0) {
                char removed = stack.pop();
                seen[removed - 'a'] = false;
            }

            // step 6 - add current character `ch` to resultant stack and mark true in seen array
            stack.push(ch);
            seen[ch - 'a'] = true;
        }

        // step 7 - build resultant string `res` from stack and return it
        StringBuilder res = new StringBuilder();
        for(char c : stack){
            res.append(c);
        }

        return new String(res);
    }

    public static void main(String[] args) {
        // String s = "bcabc";

        String s = "cbacdcbc";
        System.out.println(removeDuplicateLetters(s));
    }
}