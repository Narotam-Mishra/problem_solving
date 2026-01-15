
// Problem link - https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/?envType=daily-question&envId=2026-01-15

package Array_problems;

import java.util.Arrays;

public class MaximizeAreaOfSquareHoleIngrid {
    public static int maximizeSquareHoleArea(int n, int m, int[] hBars, int[] vBars) {
        // sort the input arrays
        Arrays.sort(hBars);
        Arrays.sort(vBars);

        // keep track of longest consecutive horizontal and vertical bars
        int maxConsecutiveHBar = 1, maxConsecutiveVBar = 1;

        // step 1 - first find length of longest consecutive horizontal bars
        int currConsecutiveHBars = 1;
        for (int i = 1; i < hBars.length; i++) {
            if (hBars[i] - hBars[i - 1] == 1) {
                currConsecutiveHBars++;
            } else {
                currConsecutiveHBars = 1;
            }
            maxConsecutiveHBar = Math.max(maxConsecutiveHBar, currConsecutiveHBars);
        }

        // step 2 - first find length of longest consecutive vertical bars
        int currConsecutiveVBars = 1;
        for (int i = 1; i < vBars.length; i++) {
            if (vBars[i] - vBars[i - 1] == 1) {
                currConsecutiveVBars++;
            } else {
                currConsecutiveVBars = 1;
            }
            maxConsecutiveVBar = Math.max(maxConsecutiveVBar, currConsecutiveVBars);
        }

        // step 3 - find side square formed
        int side = Math.min(maxConsecutiveHBar, maxConsecutiveVBar) + 1;

        // step 4 - return maximum area
        return side * side;
    }

    public static void main(String[] args) {
        int n = 2, m = 1;
        int[] hBars = {2,3}, vBars = {2};
        System.out.println(maximizeSquareHoleArea(n, m, hBars, vBars));
    }
}
