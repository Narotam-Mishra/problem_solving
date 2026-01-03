
// Problem link - https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/description/?envType=daily-question&envId=2026-01-03

package DynamicProgramming_problems;

import java.util.*;

public class NumberOfWaysToPaintGrid {
    // modulo value
    static final int MOD = 1_000_000_007;

    // predefined all valid color states for a row
    private static final String[] states = {
        "RYG","RGY","RYR","RGR",
        "YRG","YGR","YGY","YRY",
        "GRY","GYR","GRG","GYG"
    };

    // memo for memoization
    // memo[n][state] stores number of ways for `n` rows with previous row state
    private static int[][] memo;

    private static int solveRec(int n, int pr){
        // base case - if no row left to paint
        // then count 1 valid configuration
        if(n == 0) return 1;

        // return precomputed value
        if(memo[n][pr] != -1){
            return memo[n][pr];
        }

        // recursive case - try all curent row states
        int res = 0;
        for(int cr=0; cr<12; cr++){
            String currPattern = states[cr];
            boolean conflict = false;

            // check vertical conflicts
            for(int c=0; c<3; c++){
                if(currPattern.charAt(c) == states[pr].charAt(c)){
                    conflict = true;
                    break;
                }
            }

            // if there no conflict and compute number of ways
            if(!conflict){
                res = (res + solveRec(n-1, cr)) % MOD;
            }
        }

        // memoize and return
        return memo[n][pr] = res;
    }

    public static int numOfWays(int n) {
        // initialize memo with -1
        memo = new int[n][12];
        for(int i=0; i<n; i++){
            Arrays.fill(memo[i], -1);
        }

        // step 1 - try all possible first-row pattern
        int ans = 0;
        for(int i=0; i<12; i++){
            // step 2 - perform computation using recursion
            ans = (ans + solveRec(n-1, i)) % MOD;
        }

        // step 3 - return final answer, `ans`
        return ans;
    }

    public static void main(String[] args) {
        // int n = 1;

        int n = 5000;
        System.out.println(numOfWays(n));
    }
}
