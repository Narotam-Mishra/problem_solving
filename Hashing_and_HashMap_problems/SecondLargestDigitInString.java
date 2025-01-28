
// Problem link : https://leetcode.com/problems/second-largest-digit-in-a-string/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

public class SecondLargestDigitInString {
    public static int secondHighest(String s) {
        // step 1 - initialize largest and second largest variables
        int largest = -1;
        int secondLargest = -1;

        // step 2 - iterate through each character in the string
        for (char ch : s.toCharArray()) {
            if (ch >= '0' && ch <= '9') {
                int digit = ch - '0';
                // step 3 - find second largest
                // if current digit is greater than largest
                if (digit > largest) {
                    // current largest becomes second largest
                    secondLargest = largest;

                    // update largest
                    largest = digit;

                    // if digit is less than largest but greater than second largest
                } else if (digit < largest && digit > secondLargest) {
                    secondLargest = digit;
                }
            }
        }

        // step 4 - return the second largest digit
        return secondLargest;
    }

    public static void main(String[] args) {
        // String s = "dfa12321afd";

        String s = "abc1111";
        System.out.println(secondHighest(s));
    }
}