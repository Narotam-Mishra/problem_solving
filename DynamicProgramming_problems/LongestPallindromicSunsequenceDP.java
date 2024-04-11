
// Problem link - https://leetcode.com/problems/longest-palindromic-subsequence/description/

package DynamicProgramming_problems;

public class LongestPallindromicSunsequenceDP {
    private static int findLCSBottomUpDPUtility(String s1, String s2){
        int[][] dp = new int[1005][1005];
        for(int i=1; i<=s1.length(); i++){
            for(int j=1; j<=s2.length(); j++){
                if(i == 0 || j == 0) dp[i][j] = 0;
                else{
                    if(s1.charAt(i-1) == s2.charAt(j-1)){
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    }else{
                        dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
        }
        return dp[s1.length()][s2.length()];
    }

    public static int longestPalindromeSubseq(String s) {
        // find reverse of string s
        StringBuilder str = new StringBuilder(s);
        String s1 = str.reverse().toString();
        return findLCSBottomUpDPUtility(s, s1);
    }

    public static void main(String[] args) {
        String str = "bbbab";
        System.out.println(longestPalindromeSubseq(str));
    }
}