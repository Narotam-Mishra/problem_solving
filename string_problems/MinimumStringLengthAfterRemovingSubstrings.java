
// Problem link - https://leetcode.com/problems/minimum-string-length-after-removing-substrings/?envType=problem-list-v2&envId=string

package string_problems;

import java.util.*;

public class MinimumStringLengthAfterRemovingSubstrings {
    public static int minLength(String s) {
        // step 1 - uing stack to perform string operation
        Stack<Character> stack = new Stack<>();

        // step 2 - iterate on each chacter of `s`
        for (char ch : s.toCharArray()) {
            if (!stack.isEmpty()) {
                // get stack's top
                char top = stack.peek();
                // step 3 - if top + char form "AB" or "CD", then remove them, (pop top, skip
                // char)
                if ((top == 'A' && ch == 'B') || (top == 'C' && ch == 'D')) {
                    // remove pair
                    stack.pop();
                    continue;
                }
            }
            // step 4 - no pair formed, keep the character
            stack.push(ch);
        }

        // step 5 - return length of remaining characters in stack form the reduced
        // string
        return stack.size();
    }

    public static void main(String[] args) {
        // String s = "ABFCACDB";

        String s = "ACBBD";
        System.out.println(minLength(s));
    }
}