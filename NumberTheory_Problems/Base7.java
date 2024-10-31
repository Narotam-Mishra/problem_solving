
// Problem link : https://leetcode.com/problems/base-7/description/

package NumberTheory_Problems;

public class Base7 {
    public static String convertToBase7(int num) {
        // edge case: if the number is zero, its base-7 representation is "0"
        if(num == 0) return "0";

        // check if the number is negative and store this information
        boolean isNegative = num < 0;

        // work with the absolute value of num to simplify the conversion process
        num = Math.abs(num);
        StringBuilder formBase7 = new StringBuilder();

        // convert the number to base 7 by repeatedly dividing by 7
        while(num > 0){
            // append the remainder (next base-7 digit) to base7
            formBase7.append(num % 7);

            // update num to the quotient of the division by 7
            num = num / 7;
        }

         // if the original number was negative, append '-' to the result
        if(isNegative) formBase7.append("-");
        
        // reverse the string to get the correct base-7 representation
        return formBase7.reverse().toString();
    }

    public static void main(String[] args) {
        // int num = 100;

        int num = -7;
        System.out.println(convertToBase7(num));
    }
}