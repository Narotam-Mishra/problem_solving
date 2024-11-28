
// Problem link : https://leetcode.com/problems/largest-odd-number-in-string/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

package string_problems;

public class LargestOddNumberInString {
    public static String largestOddNumber(String num) {
        // start from the last digit and move backward
        for(int i=num.length()-1; i>=0; i--){
            // convert the character to a number and check if it's odd
            if((num.charAt(i) - '0') % 2 != 0){
                // if odd, return the substring from the start to this position
                return num.substring(0, i+1);
            }
        }
        // if no odd digit is found, return an empty string
        return "";
    }
    
    public static void main(String[] args) {
        // String num = "52";

        // String num = "4206";

        String num = "35427";
        System.out.println(largestOddNumber(num));
    }
}