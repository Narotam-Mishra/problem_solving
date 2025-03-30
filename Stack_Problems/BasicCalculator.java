
// Problem link - https://leetcode.com/problems/basic-calculator/?envType=problem-list-v2&envId=string

package Stack_Problems;

import java.util.*;

public class BasicCalculator {
    public static int calculate(String s) {
        // step 1 - use stack to evalute the expression
        Stack<Integer> stack = new Stack<>();

        // step 2 - intialize all necessary variables
        int sign = 1;
        int res = 0;
        int num = 0;

        // step 3 - iterate on each character of input string `s` and evalute expression
        for (char ch : s.toCharArray()) {
            // if current character is number then format it
            if (ch >= '0' && ch <= '9') {
                num = (num * 10) + (ch - '0');
            } else if (ch == '+') {
                // evalutate the expression from left for '+'
                res += sign * num;

                // save recent sign
                sign = 1;

                // reset the number `num`
                num = 0;
            } else if (ch == '-') {
                // evalutate the expression from left for '+'
                res += sign * num;

                // save recent sign
                sign = -1;

                // reset the number `num`
                num = 0;
            } else if (ch == '(') {
                // push result `res` and `sign` onto stack for `(`
                stack.push(res);
                stack.push(sign);

                // reset sign and result `res` for new expression
                res = 0;
                sign = 1;
            } else if (ch == ')') {
                // evaluate current expression
                res += sign * num;

                // `)` marks end of expression so pop from stack for sign of expression
                res *= stack.pop();

                // add result for expression
                res += stack.pop();

                // reset number `num`
                num = 0;
            }
        }

        // step 4 - add and return last number to result `res`
        return res + (sign * num);
    }

    public static void main(String[] args) {
        // String s = "1 + 1";

        // String s = "2-1 + 2 ";

        String s = "(1+(4+5+2)-3)+(6+8)";
        System.out.println(calculate(s));
    }
}