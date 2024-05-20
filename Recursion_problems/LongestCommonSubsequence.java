
// Problem link - https://leetcode.com/problems/longest-common-subsequence/

// Approach - using Recursion 

package Recursion_problems;

public class LongestCommonSubsequence {
    private static int findLCSRec(String s1,String s2, int i, int j){
        // Base case: if any of the string has been exhausted then return 0
        if(i == -1 || j == -1) return 0;

        // Recursive case1: if the current character from each string is equal
        // then add current character length and recursively call the function on remaining characters
        if(s1.charAt(i) == s2.charAt(j)){
            return 1 + findLCSRec(s1, s2, i-1, j-1);
        }else{
            // Recursive case2: either exclude current character from 1st string or 2nd string
            int l1 = findLCSRec(s1, s2, i-1, j);
            int l2 = findLCSRec(s1, s2, i, j-1);
            // and return maximum length 
            return Math.max(l1, l2);
        }
    }
    public static int longestCommonSubsequence(String text1, String text2) {
        return findLCSRec(text1, text2, text1.length()-1, text2.length()-1);
    }

    public static void main(String[] args) {
        String s1 = "abcde";
        String s2 = "ace" ;

        // String s1 = "abc";
        // String s2 = "abc" ;

        // String s1 = "abc";
        // String s2 = "def" ;
        System.out.println(longestCommonSubsequence(s1, s2));
    }
}