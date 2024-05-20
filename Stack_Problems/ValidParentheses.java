
// Problem link - https://leetcode.com/problems/valid-parentheses/description/

package Stack_Problems;

import java.util.Stack;

public class ValidParentheses {
    public static boolean isValid(String s) {
        Stack<Character> stack = new Stack<Character>();
        for(int i=0; i<s.length(); i++){
            char curChar = s.charAt(i);
            // if current character is opening parentheses, then push into stack
            if(curChar == '(' || curChar == '{' || curChar == '['){
                stack.push(curChar);
            }else{
                // if stack is empty, then return false
                if(stack.isEmpty()) return false;
                // Pop the top element from the stack
                char chTop = stack.pop();
                // Check if the current closing bracket matches the last opening bracket
                if((curChar == ')' && chTop != '(') || (curChar == '}' && chTop != '{') || (curChar == ']' && chTop != '[')){
                    // if any of above conditions match then return false
                    return false;
                }
            }
        }
        return stack.isEmpty();
    }

    public static void main(String[] args) {
        // String str = "()[]{}";

        String str = "(]";
        System.out.println(isValid(str));
    }
}
