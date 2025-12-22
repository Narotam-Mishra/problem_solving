package string_problems;

import java.util.*;

public class DeleteColumnsToMakeSortedIII {
    public static int minDeletionSize(String[] strs) {
        // get rows and columns size
        int r = strs.length;
        int c = strs[0].length();

        // dp[i] = length of the longest valid column sequence ending at column `i`
        int[] dp = new int[c];
        Arrays.fill(dp, 1);

        // keep track of LIS length
        int LIS = 0;

        // step 1 - using Longest Increasing Subsequence technique
        for(int i=0; i<c; i++){
            for(int j=0; j<i; j++){
                // flag to check if LIS condition hold true for all strings
                boolean isValid = true;

                // step 2 - check for all strings (row wise)
                for(int k=0; k<r; k++){
                    // check if column j can come before column i
                    if(strs[k].charAt(j) > strs[k].charAt(i)){
                        isValid = false;
                        break;
                    }
                }

                // if valid, update dp[i]
                if(isValid){
                    dp[i] = Math.max(dp[i], dp[j]+1);
                }
            }

            // step 3 - update LIS length
            LIS = Math.max(LIS, dp[i]);
        }

        // step 4 - return minimum deletion required
        return c-LIS;
    }

    public static void main(String[] args) {
        // String[] strs = {"babca", "bbazb"};

        // String[] strs = {"edcba"};

        String[] strs = {"ghi","def","abc"};
        System.out.println(minDeletionSize(strs));
    }
}
