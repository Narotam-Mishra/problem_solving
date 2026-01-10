
// Problem link - https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/?envType=daily-question&envId=2026-01-10

package DynamicProgramming_problems;

import java.util.*;

public class MinimumASCIIDeleteSumForTwoStrings {
    private static  int m, n;
    private static int[][] memo;

    private static  int solveRec(int i, int j, String s1, String s2){
        // base case: both strings finished
        if(i >= m && j >= n){
            return 0;
        }

        // already computed
        if(memo[i][j] != -1){
            return memo[i][j];
        }

        // recursive case
        // s1 is exhausted -> delete remaining s2
        if(i >= m){
            return s2.charAt(j) + solveRec(i, j+1, s1, s2);
        }

        // s2 exhausted -> delete remaining s1
        if(j >= n){
            return s1.charAt(i) + solveRec(i+1, j, s1, s2);
        }

        // characters match → no cost
        if(s1.charAt(i) == s2.charAt(j)){
            return solveRec(i+1, j+1, s1, s2);
        }

        // option 1 - delete s1
        int delS1 = s1.charAt(i) + solveRec(i+1, j, s1, s2);

        // option 2
        int delS2 = s2.charAt(j) + solveRec(i, j+1, s1, s2);

        // memoize and return minimum cost
        return memo[i][j] = Math.min(delS1, delS2);
    }

    public static int minimumDeleteSum(String s1, String s2) {
        // find size of s1 and s2
        m = s1.length();
        n = s2.length();

        // reset memoization
        memo = new int[m+1][n+1];
        for (int[] row : memo) {
            Arrays.fill(row, -1);
        }

        // step 1 - solve recursively and return
        return solveRec(0, 0, s1, s2);
    }

    public static void main(String[] args) {
        String s1 = "sea", s2 = "eat";

        // String s1 = "delete", s2 = "leet";
        System.out.println(minimumDeleteSum(s1, s2));
    }
}
