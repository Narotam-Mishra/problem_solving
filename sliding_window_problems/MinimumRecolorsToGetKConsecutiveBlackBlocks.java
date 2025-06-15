
// Problem link - https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/?envType=problem-list-v2&envId=sliding-window

package sliding_window_problems;

public class MinimumRecolorsToGetKConsecutiveBlackBlocks {
    public static int minimumRecolors(String blocks, int k) {
        int n = blocks.length();

        // step 1 - count white blocks in first window of size `k`
        int whiteCount = 0;
        for(int i=0; i<k; i++){
            if(blocks.charAt(i) == 'W'){
                whiteCount++;
            }
        }
 
        // step 2- initialize minimum operations with first window
        int minOperations = whiteCount;

        // step 3 - slide the window across the remaining string starting from `k`
        for(int i=k; i<n; i++){
            // step 4 - remove leftmost character from window if that is white `W`
            if(blocks.charAt(i-k) == 'W'){
                whiteCount--;
            }

            // step 5 - add new chracter to the rightmost window, if that is white `W`
            if(blocks.charAt(i) == 'W'){
                whiteCount++;
            }

            // step 6 - update minimum operations
            minOperations = Math.min(minOperations, whiteCount);

            // early termination if minimum operation is 0
            if(minOperations == 0){
                break;
            }
        }

        // step 7 - return minimum operations, `minOperations`
        return minOperations;
    }

    public static void main(String[] args) {
        // String blocks = "WBBWWBBWBW";
        // int k = 7;

        String blocks = "WBWBBBW";
        int k = 2;
        System.out.println(minimumRecolors(blocks, k));
    }
}