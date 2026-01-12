
// Problem link - https://leetcode.com/problems/minimum-time-visiting-all-points/?envType=daily-question&envId=2026-01-12

package NumberTheory_Problems;

public class MinimumTimeVisitingAllPoints {
    public static int minTimeToVisitAllPoints(int[][] points) {
        int n = points.length;
        
        // keep track of total time needed
        int steps = 0;

        // step 1 - visit points in the given order
        for (int i = 0; i < n - 1; i++) {
            // current point
            int x1 = points[i][0];
            int y1 = points[i][1];

            // next point
            int x2 = points[i + 1][0];
            int y2 = points[i + 1][1];

            // step 2 - find distance in x and y directions
            int dx = Math.abs(x2 - x1);
            int dy = Math.abs(y2 - y1);

            /*
             * Diagonal moves: min(dx, dy)
             * Straight moves: |dx - dy|
             */

            // step 3 - calculate time to visit all points
            steps += Math.min(dx, dy) + Math.abs(dx - dy);
        }

        // step 4 - return minimum time
        return steps;
    }

    public static void main(String[] args) {
        // int[][] points = {{1,1},{3,4},{-1,0}};

        int[][] points = {{3,2},{-2,2}};
        System.out.println(minTimeToVisitAllPoints(points));
    }
}
