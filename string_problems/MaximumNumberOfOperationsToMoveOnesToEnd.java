
// Problem link - https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/?envType=daily-question&envId=2025-11-13

package string_problems;

public class MaximumNumberOfOperationsToMoveOnesToEnd {
    public static  int maxOperations(String s) {
        int n = s.length();

        int ops = 0;

        // step 1 - whenever we ecounter 0, find operations
        // operation will count of 1 seen so far, ops += count1
        int c1 = 0, i = 0;
        while (i < n) {
            if (s.charAt(i) == '0') {
                ops += c1;

                // step 2 - move till first 1 or occurence
                while (i < n && s.charAt(i) == '0') {
                    i++;
                }
            } else {
                // step 3 - check if s[i] is still '1'
                // continue incrementing count of 1
                c1++;
                i++;
            }
        }

        // step 4 - return the maximum number of operations
        return ops;
    }

    public static void main(String[] args) {
        // String s = "1001101";

        String s = "00111";
        System.out.println(maxOperations(s));
    }
}
