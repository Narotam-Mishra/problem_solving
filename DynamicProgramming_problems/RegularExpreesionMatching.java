
// Problem link - https://leetcode.com/problems/regular-expression-matching/?envType=problem-list-v2&envId=string

package DynamicProgramming_problems;

public class RegularExpreesionMatching {
    public static boolean isMatch(String s, String p) {
        // step 1 - create dp array of boolean
        boolean[][] dp = new boolean[s.length()+1][p.length()+1];

        // step 2 - iterate on dp table and fill it required value
        int mr = dp.length-1;
        int mc = dp[0].length-1;

        for(int i=0; i<=mr; i++){
            for(int j=0; j<=mc; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = true;
                }else if(j == 0){
                    dp[i][j] = false;
                }else if(i == 0){
                    char chp = p.charAt(j - 1);
                    if(chp == '*'){
                        dp[i][j] = dp[i][j-2];
                    }else{
                        dp[i][j] = false;
                    }
                }else{
                    char chp = p.charAt(j-1);
                    char chs = s.charAt(i-1);

                    if(chp == '*'){
                        dp[i][j] = dp[i][j-2];

                        char chpprev = p.charAt(j-2);
                        if(chpprev == '.' || chpprev == chs) {
                            dp[i][j] = dp[i][j] || dp[i-1][j];
                        }
                    }else if(chp == '.'){
                        dp[i][j] = dp[i-1][j-1];
                    }else if(chp == chs){ 
                        dp[i][j] = dp[i-1][j-1];
                    }else{
                        dp[i][j] = false;
                    }
                }
            }
        }

        // step 3 - return final output 
        return dp[mr][mc];
    }

    public static void main(String[] args) {
        // String s = "aa", p = "a";

        String s = "aa", p = "a*";

        // String s = "ab", p = ".*";
        System.out.println(isMatch(s, p));
    }
}