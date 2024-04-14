
// Problem link - https://leetcode.com/problems/longest-palindromic-subsequence/description/

// Approach - using Top Down DP

package DynamicProgramming_problems;

public class LongestPallindromicSubsequenceDP {
    public static int[][] dp = new int[1005][1005]; 
    private static int findLPS_TopDownDP(String str, int i, int j){
        // Base case if bothe indices i and j are equal return 1
        if(i == j) return 1;

        // if ith index surpass jth index that means no pallindromic string is possible
        // return 0
        if(i > j) return 0;

        // if dp[i][j] is already computed then return dp[i][j]
        if(dp[i][j] != -1) return dp[i][j];

        // if terminal characters are equal , add their contribution
        // and recursively call the function on remaning characters
        if(str.charAt(i) == str.charAt(j)){
            return dp[i][j] =  2 + findLPS_TopDownDP(str, i+1, j-1);
        }else{
            // otherwise recursively call the function on remaning characters
            return dp[i][j] = Math.max(findLPS_TopDownDP(str, i+1, j), findLPS_TopDownDP(str, i, j-1));
        }
    }
    public static int longestPalindromeSubseq(String s) {
        for(int i=0; i<1005; i++){
            for(int j=0; j<1005; j++){
                dp[i][j] = -1;
            }
        }
        return findLPS_TopDownDP(s, 0, s.length()-1);
    }

    public static void main(String[] args) {
        String str = "bbbab";
        System.out.println(longestPalindromeSubseq(str));
    }
}
