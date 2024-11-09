
// Problem link : https://leetcode.com/problems/count-the-digits-that-divide-a-number/description/

package NumberTheory_Problems;

public class CountDigitsThatDivideNumber {
    public static int countDigits(int num) {
        // intialize counter 'count' to keep track of count
        int count = 0;

        // conver to string for easy iteration
        String numStr = String.valueOf(num);

        // iterate through each digit of string format number
        for(int i=0; i<numStr.length(); i++){
            // change digit to number
            int digit = numStr.charAt(i)- '0';

            if(digit != 0 && num % digit == 0){
                // if each non-zero digit divde the number 'num', 
                // increment count
                count++;
            }
        }
        // return the resultant counter 'count'
        return count;
    }

    public static void main(String[] args) {
        // int num = 123;

        int num = 1248;
        System.out.println(countDigits(num));
    }
}