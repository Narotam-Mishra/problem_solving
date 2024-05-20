
// Problem link - https://leetcode.com/problems/backspace-string-compare/description/

package Stack_Problems;

import java.util.Stack;

public class BackspaceStringCompare {
    public static boolean backspaceCompare(String s, String t) {
        // used two stacks to manage strings s & t
        Stack<Character> st1 = new Stack<>();
        Stack<Character> st2 = new Stack<>();

        // iterate string s
        for(int i=0; i<s.length(); i++){
            // if current character is not '#' then push it into stack st1
            if(s.charAt(i) != '#'){
                st1.push(s.charAt(i));
            }else{
                // otherwise pop it from stack st1
                if(st1.size() > 0) st1.pop();
            }
        }

        // iterate string t
        for (int i = 0; i < t.length(); i++) {
            // if current character is not '#' then push it into stack st2
            if (t.charAt(i) != '#') {
                st2.push(t.charAt(i));
            } else {
                // otherwise pop it from stack st1
                if (st2.size() > 0)
                    st2.pop();
            }
        }

        // compare both strings using stack top
        while (st1.size() > 0 && st2.size() > 0) {
            if (st1.peek() != st2.peek())
                return false;
            st1.pop();
            st2.pop();
        }

        // if both stacks are empty that means both strings are equal 
        // return true
        return (st1.size() == 0 && st2.size() == 0);
    }

    public static void main(String[] args) {
        String s = "ab#c", t = "ad#c";
        System.out.println(backspaceCompare(s, t));
    }
}