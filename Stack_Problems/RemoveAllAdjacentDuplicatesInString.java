
// Problem link - https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/

package Stack_Problems;

import java.util.*;

public class RemoveAllAdjacentDuplicatesInString {
    public static String removeDuplicates(String s) {
        Stack<Character> stack = new Stack<>();

        for(int i=0; i<s.length(); i++){
            char curChar = s.charAt(i);
            if(!stack.isEmpty() && curChar == stack.peek()){
                // if current character of string is equal to stack's top then pop from stack
                stack.pop();
            }else{
                // otherwise push current character of string into string
                stack.push(curChar);
            }
        }

        // Build the resulting string from the characters in the stack
        StringBuilder sb = new StringBuilder();
        for(char ch : stack){
            sb.append(ch);
        }

        // return result string 'sb'
        return sb.toString();
    }

    public static void main(String[] args) {
        String str = "abbaca";
        System.out.println(removeDuplicates(str)); // Expected output: "ca"
    }
}