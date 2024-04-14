
// Problem link - https://leetcode.com/problems/longest-palindromic-subsequence/

// Approach - using Recursion


package Recursion_problems;

public class LongestPallindromicSubSequenceRec {
    private static int findLPS_Recursion(String str, int i, int j){
        // Base case if bothe indices i and j are equal return 1
        if(i == j) return 1;

        // if ith index surpass jth index that means no pallindromic string is possible
        // return 0
        if(i > j) return 0;

        // if terminal characters are equal , add their contribution
        // and recursively call the function on remaning characters
        if(str.charAt(i) == str.charAt(j)){
            return 2 + findLPS_Recursion(str, i+1, j-1);
        }else{
            // otherwise recursively call the function on remaning characters
            return Math.max(findLPS_Recursion(str, i+1, j), findLPS_Recursion(str, i, j-1));
        }
    }
    public static int longestPalindromeSubseq(String s) {
        return findLPS_Recursion(s, 0, s.length()-1);
    }

    public static void main(String[] args) {
        String str = "bbbab";
        System.out.println(longestPalindromeSubseq(str));
    }
}
