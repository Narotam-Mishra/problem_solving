
// Problem link - https://leetcode.com/problems/clear-digits/description/?envType=problem-list-v2&envId=string

package string_problems;

import java.util.Stack;

public class ClearDigits {
    public static String clearDigits(String s) {
        // step 1 - use stack to store non-digit characters
        Stack<Character> stack = new Stack<>();

        // step 2 - iterate on each character of input string `s`
        for(char ch : s.toCharArray()){
            // step 3 - check if it is digit, remove the closest non-digit from stack
            if(Character.isDigit(ch)){
                // check stack size to remove top element
                if(stack.size() > 0){
                    stack.pop();
                }
            }else{
                // step 4 - push non-digit characters onto the stack
                stack.push(ch);
            }
        }

        // step 5 - construct the resulting string
        StringBuilder res = new StringBuilder();
        for(char ch : stack){
            res.append(ch);
        }

        // step 6 - return res
        return res.toString();
    }

    public static void main(String[] args) {
        // String s = "abc";

        String s = "cb34";
        System.out.println(clearDigits(s));
    }
}