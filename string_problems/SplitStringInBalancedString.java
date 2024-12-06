
// Problem link : https://leetcode.com/problems/split-a-string-in-balanced-strings/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

package string_problems;

public class SplitStringInBalancedString {
    public static int balancedStringSplit(String s) {
        // initialize counters for balance and result
        // tracks the current balance of 'L' and 'R'
        int lrCount = 0;

        // counts the maximum number of balanced substrings
        int maxCount = 0;

        // iterate through each character in the string
        for (char ch : s.toCharArray()) {
            // update lrCount: +1 for 'L', -1 for 'R'
            if (ch == 'L') {
                lrCount++;
            } else {
                lrCount--;
            }

            // if balance is zero, a balanced substring is found
            if (lrCount == 0)
                maxCount++;
        }

        // return the total number of balanced substrings
        return maxCount;
    }

    public static void main(String[] args) {
        // String str = "RLRRLLRLRL";

        // String str = "RLRRRLLRLL";

        String str = "LLLLRRRR";
        System.out.println(balancedStringSplit(str));
    }
}