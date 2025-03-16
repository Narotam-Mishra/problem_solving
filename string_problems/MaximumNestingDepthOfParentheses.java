
// Problem link - https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/?envType=problem-list-v2&envId=string

package string_problems;

public class MaximumNestingDepthOfParentheses {
    public static int maxDepth(String s) {
        // step 1 - track current depth and maximu depth in `depth` & `maxiDepth` 
        int depth = 0, maxiDepth = 0;

        // step 2 - iterate on string `s`
        for(char ch : s.toCharArray()){
            if(ch == '('){
                // step 3 - increase depth for every opening parenthesis
                depth++;

                // step 4 - find maximum depth `maxiDepth`
                maxiDepth = Math.max(maxiDepth, depth);
            }else if(ch == ')'){
                // step 5 - decrease depth for every closing parenthesis
                depth--;
            }
        }

        // step 6 - return max depth
        return maxiDepth;
    }

    public static void main(String[] args) {
        // String s = "(1+(2*3)+((8)/4))+1";

        // String s = "(1)+((2))+(((3)))";

        String s = "()(())((()()))";
        System.out.println(maxDepth(s));
    }
}