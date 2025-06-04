
// Problem link - https://leetcode.com/problems/make-the-string-great/?envType=problem-list-v2&envId=string

package Stack_Problems;

import java.util.Stack;

public class MakeTheStringGreat {
    private static boolean formBadPair(char ch1, char ch2){
        // check if they are the same letter (case-insensitive)
        boolean sameLetterDifferentCase = Character.toLowerCase(ch1) == Character.toLowerCase(ch2);

        // check if they have different cases (original characters are different)
        boolean differentCase = ch1 != ch2;

        // above both conditions must be true for a bad pair
        return sameLetterDifferentCase && differentCase;
    }
    
    public static String makeGood(String s) {
        // step 1 - use stack to perfrom given operation
        Stack<Character> stack = new Stack<>();

        // step 2 - iterate on each character of the input string `s`
        for(int i=0; i<s.length(); i++){
            // get current character
            char currChar = s.charAt(i);

            // step 3 - if stack is empty add current character
            if(stack.empty()){
                stack.push(currChar);
                continue;
            }

            // get last character from stack top
            char lastChar = stack.peek();

            // step 4 - check if current char and last char form bad pair 
            if(formBadPair(currChar, lastChar)){
                // remove bad pair by popping from stack
                stack.pop();
            }else{
                // otherwise push into stack
                stack.push(currChar);
            }
        }

        // step 4 - build result from stack
        StringBuilder res = new StringBuilder();
        for(char ch : stack){
            res.append(ch);
        }

        // step 5 - return resultant string `res`
        return res.toString();
    }

    public static void main(String[] args) {
        // String s = "leEeetcode";

        // String s = "abBAcC";

        String s = "s";
        System.out.println(makeGood(s));
    }
}