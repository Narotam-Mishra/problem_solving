
// Problem link - https://leetcode.com/problems/valid-number/description/

package string_problems;

public class ValidNumber {
    public static boolean isNumber(String s) {
        // step 1 - trim any leading or trailing whitspaces from string `s`
        s = s.trim();

        // step 2 - determine regular expression to match valid number format
        String validNumberPattern = "^[\\+\\-]?((\\d+\\.\\d*)|(\\.\\d+)|(\\d+))([eE][\\+\\-]?\\d+)?$";

        // step 3 - test if string matches valid number regular expression
        return s.matches(validNumberPattern);
    }

    public static void main(String[] args) {
        // String s = "0";

        // String s = "e";

        // String s = ".";

        // String s = "99e2.";

        // String s = "95a54e53";

        // String s = "53.5e93";

        // String s = "3e+7";

        // String s = "-90E3";

        // String s = "4.";

        String s = "-.9";
        System.out.println(isNumber(s));
    }
}