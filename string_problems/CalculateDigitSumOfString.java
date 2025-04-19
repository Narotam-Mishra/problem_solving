
// Problem link - https://leetcode.com/problems/calculate-digit-sum-of-a-string/description/?envType=problem-list-v2&envId=string

package string_problems;

public class CalculateDigitSumOfString {
    public static String digitSum(String s, int k) {
        // step 1 - continue until input string `s` length is greater than `k`
        while(s.length() > k){
            // store newly transformed string `s` to a variable `newStr`
            StringBuilder newStr = new StringBuilder();

            // step 2 - process string `s` in k chunks
            for(int i=0; i<s.length(); i+=k){

                // step 3 - calculate sum of digits in each group
                int sum = 0;
                for(int j=i; j<Math.min(i+k, s.length()); j++){
                    sum += s.charAt(j) - '0';
                }

                // step 4 - append the digit sum to the new string
                newStr.append(sum);
            }

            // step 5 - update `s` to newly formed string `newStr`
            s = newStr.toString();
        }

        // step 6 - return the final string once its length is <= k
        return s;
    }

    public static void main(String[] args) {
        // String s = "11111222223";
        // int k = 3;

        String s = "00000000";
        int k = 3;
        System.out.println(digitSum(s, k));
    }
}