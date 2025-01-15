
// Problem link : https://leetcode.com/problems/permutation-difference-between-two-strings/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

public class PermutationDifferenceBetweenTwoStrings {
    public static int findPermutationDifference(String s, String t) {
        // step 1 - initialize variable to store absolute difference
        int absDiff = 0;

        // step 2 - iterate over the any of input string
        for(int i=0; i<s.length(); i++) {
            // get first character
            char ch = s.charAt(i);

            // get index of that first character in target string `t`
            int i2 = t.indexOf(ch);

            // step 3 - find sum of absolute difference
            absDiff += Math.abs(i - i2);
        }

        // step 4 - return sum of absolute difference
        return absDiff;
    }

    public static void main(String[] args) {
        // String s = "abc", t = "bac";

        String s = "abcde", t = "edbac";
        System.out.println(findPermutationDifference(s, t));
    }
}