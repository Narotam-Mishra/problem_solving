
// Problem link - https://leetcode.com/problems/sum-of-digits-of-string-after-convert/?envType=problem-list-v2&envId=string

package string_problems;

public class SumOfDigitsOfStringAfterConvert {
    public static int getLucky(String s, int k) {
        // step 1 - convert each character in the string to its corresponding position in the alphabet
        // and calculate the sum of its digits
        int sum = 0;
        for(char ch : s.toCharArray()){
            int digit = ch - 'a' + 1;
            sum += digit / 10 + digit % 10;
        }

        // step 2 - perform the transformation k-times
        for(int i=1; i<k; i++){
            int nextSum = 0;
            while(sum > 0){
                nextSum += sum%10;
                sum = sum/10;
            }
            sum = nextSum;
        }

        // step 3 - return the final sum
        return sum;
    }

    public static void main(String[] args) {
        // String s = "iiii";
        // int k = 1;

        // String s = "leetcode";
        // int k = 2;

        String s = "zbax";
        int k = 2;
        System.out.println(getLucky(s, k));
    }
}