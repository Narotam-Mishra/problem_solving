
// Problem link - https://leetcode.com/problems/jump-game-v/description/?envType=daily-question&envId=2026-05-24

package DynamicProgramming_problems;

import java.util.*;

public class JumpGameV {
    int n;

    // memo[i] stores the maximum number of indices reachable starting at i
    int[] memo;

    // recursive helper with memoization.
    private int solveRec(int i, int[] arr, int d){
        // return cached result if available
        if(memo[i] != -1) return memo[i];

        // keep track of maximum number of indices visited
        int ans = 1;

        // case 1 - traverse left path
        for(int j=i-1; j>=Math.max(0, i-d); j--){
            if(arr[j] >= arr[i]) break;
            ans = Math.max(ans, 1 + solveRec(j, arr, d));
        }

        // case 2 - traverse right path
        for(int j=i+1; j<=Math.min(n-1, i+d); j++){
            if(arr[j] >= arr[i]) break;
            ans = Math.max(ans, 1 + solveRec(j, arr, d));
        }

        // cache and return
        return memo[i] = ans;
    }

    public int maxJumps(int[] arr, int d) {
        n = arr.length;

        // step 1 - initialize memo size to n and mark all as uncomputed
        memo = new int[n+1];
        Arrays.fill(memo, -1);

        // step 2 - try starting from each index and take the best result
        int res = 0;
        for(int i=0; i<n; i++){
            res = Math.max(res, solveRec(i, arr, d));
        }

        // step 3 - return maximum number of indices visited
        return res;
    }

    public static void main(String[] args) {
        int[] arr = {6,4,14,6,8,13,9,7,10,6,12};
        int d = 2;
        JumpGameV obj = new JumpGameV();
        System.out.println(obj.maxJumps(arr, d));
    }
}
