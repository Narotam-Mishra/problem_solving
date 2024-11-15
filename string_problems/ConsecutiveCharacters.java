
// Problem link : https://leetcode.com/problems/consecutive-characters/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

package string_problems;

public class ConsecutiveCharacters {
    public static int maxPower(String s) {
        // initialize variables
        // start with the first character
        char currChar = s.charAt(0);

        // length of the current sequence
        int curPow = 1;

        // at least one character guarantees power 1
        int maxPower = 1;

        // iterate through the string starting from the second character
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == currChar) {
                // continue the sequence
                curPow++;
            } else {
                // sequence ends, update maxPower if needed
                maxPower = Math.max(maxPower, curPow);

                // reset for the new character
                currChar = s.charAt(i);
                curPow = 1;
            }
        }

        // final comparison to account for the last sequence
        maxPower = Math.max(maxPower, curPow);
        return maxPower;
    }

    public static void main(String[] args) {
        // String str = "leetcode";

        String str = "abbcccddddeeeeedcba";
        System.out.println(maxPower(str));
    }
}