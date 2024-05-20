
// Problem link - https://leetcode.com/problems/removing-stars-from-a-string/description/

package Stack_Problems;

import java.util.Stack;

public class RemoveStarsFromString {
    public static String removeStars(String s) {
        Stack<Character> stack = new Stack<>();

        for(int i=0; i<s.length(); i++){
            if(s.charAt(i) != '*'){
                stack.push(s.charAt(i));
            }else{
                if(!stack.isEmpty())
                    stack.pop();
            }
        }

        StringBuilder res = new StringBuilder();
        while (!stack.isEmpty()) {
            res.insert(0, stack.pop());
        }
        return res.toString();
    }

    public static void main(String[] args) {
        String str = "leet**cod*e";
        System.out.println(removeStars(str));
    }
}
