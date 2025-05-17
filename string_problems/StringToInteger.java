
// Problem link - https://leetcode.com/problems/string-to-integer-atoi/description/

package string_problems;

public class StringToInteger {
    public static int myAtoi(String s) {
        // intialize necessary variables
        int i = 0, n = s.length();
        int sign = 1;
        long res = 0;

        // step 1 - skip whispaces in `s`
        while(i < n && s.charAt(i) == ' '){
            i++;
        }

        // step 2 - handle sign
        if(i < n && (s.charAt(i) == '-' || s.charAt(i) ==  '+')){
            sign = s.charAt(i) == '-' ? -1 : 1;
            i++;
        }

        // step 3 - convert numeric character to numeric number
        while(i < n && Character.isDigit(s.charAt(i))){
            int digit = s.charAt(i) - '0';

            // step 4 - check for overflow / underflow
            if(res > (Integer.MAX_VALUE - digit) / 10){
                return sign == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }

            res = res * 10 + digit;
            i++;
        }

        // step 5 - return resultant number by applying sign
        return (int)res * sign;
    }

    public static void main(String[] args) {
        // String s = "42";

        // String s = "-042";

        // String s = "1337c0d3";

        // String s = "0-1";

        String s = "words and 987";
        System.out.println(myAtoi(s));
    }
}