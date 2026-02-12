
// Problem link - https://leetcode.com/problems/longest-balanced-substring-i/description/?envType=daily-question&envId=2026-02-12

package string_problems;

public class LongestBallancedSubstringI {
    // utility function to balanced substring
    private static boolean isBalancedString(int[] frq){
        int commonFrq = 0;
        for(int i=0; i<26; i++){
            if(frq[i] == 0) continue;

            if(commonFrq == 0){
                commonFrq = frq[i];
            }else if(commonFrq != frq[i]){
                return false;
            }
        }
        return true;
    }

    public static int longestBalanced(String s) {
        int n = s.length();

        // keep track of length of the longest balanced substring
        int maxLen = 0;

        // step 1 - iterate on each character o
        for(int i=0; i<n; i++){
            // keep track of frequency
            int[] frq = new int[26];

            // step 2 - iterate on each substring
            for(int j=i; j<n; j++){
                int idx = s.charAt(j) - 'a';
                frq[idx]++;

                // step 3 - check if substring is balanced or not
                if(isBalancedString(frq)){
                    // step 4 - update maximum length of balanced substring
                    maxLen = Math.max(maxLen, j-i+1);
                }
            }
        }

        // step 5 - return longest balanced substring
        return maxLen;
    }

    public static void main(String[] args) {
        // String s = "abbac";

        // String s = "zzabccy";

        String s = "aba";
        System.out.println(longestBalanced(s));
    }
}
