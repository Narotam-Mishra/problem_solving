
// Problem link - https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/description/?envType=problem-list-v2&envId=array

package Array_problems;

import java.util.*;

public class WidestVerticalAreaBetweenTwoPointsContainingNoPoints {
    public static int maxWidthOfVerticalArea(int[][] points) {
        // step 1 - extract and sort x-coordinates
        // we only care about x-coordinates since we're looking for vertical gaps
        int[] xPoints = new int[points.length];
        for (int i = 0; i < points.length; i++) {
            xPoints[i] = points[i][0];
        }

        // sort x-coordinates
        Arrays.sort(xPoints);

        // step 2 - find the maximum gap between consecutive x-coordinates
        int maxWidth = 0;
        for (int i = 1; i < xPoints.length; i++) {
            int currentWidth = xPoints[i] - xPoints[i - 1];

            // step 3 - update maximum width
            maxWidth = Math.max(maxWidth, currentWidth);
        }

        // step 4 - return maximum widest vertical area
        return maxWidth;
    }

    public static void main(String[] args) {
        // int[][] points = {{8,7}, {9,9}, {7,4}, {9,7}};

        int[][] points = {{3,1}, {9,0}, {1,0}, {1,4}, {5,3}, {8,8}};
        System.out.println(maxWidthOfVerticalArea(points));
    }
}
