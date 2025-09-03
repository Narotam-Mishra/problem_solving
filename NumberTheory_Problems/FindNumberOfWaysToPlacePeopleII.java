
// Problem link - https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/?envType=daily-question&envId=2025-09-03

package NumberTheory_Problems;

import java.util.*;
import java.util.stream.Collectors;

public class FindNumberOfWaysToPlacePeopleII {
    public static int numberOfPairs(int[][] points) {
        // find size of points
        int n = points.length;

        // store count of valid points
        int count = 0;

        // step 1 - sort points by x-coordinate, then by y-coordinate (descending)
        List<int[]> sortedPoints = Arrays.stream(points)
            .sorted((a, b) -> {
                if (a[0] != b[0]) return Integer.compare(a[0], b[0]);
                return Integer.compare(b[1], a[1]);
            })
            .collect(Collectors.toList());

        // step 2 - now iterate over possible x and y co-ordinates
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                // extract co-ordinate points
                int[] A = sortedPoints.get(i);
                int[] B = sortedPoints.get(j);

                // step 3 - check A.y >= B.y (A is on upper left of B)
                // no need to check x point as it sorted i.e A.x <= B.x
                if (A[1] >= B[1]) {
                    // step 4 - check second condition : there is no points inside rectangle
                    boolean hasPointsInside = false;

                    // check every other possible points to see if it lies in the rectangle
                    for (int k = i+1; k<j && !hasPointsInside; k++) {
                        // extract co-ordinate points
                        int[] point = sortedPoints.get(k);
                        int x = point[0];
                        int y = point[1];

                        // check if this point lies inside rectangle or not
                        if (x >= A[0] && x <= B[0] && y >= B[1] && y <= A[1]) {
                            hasPointsInside = true;
                            break;
                        }
                    }

                    // step 5 - if no points lies inside rectangle
                    if (!hasPointsInside) {
                        // this is valid pair, so increment count
                        count++;
                    }
                }
            }
        }

        // step 6 - return valid count
        return count;
    }

    public static void main(String[] args) {
        int[][] points = {{1,1},{2,2},{3,3}};

        // int[][] points = {{6,2},{4,4},{2,6}};

        // int[][] points = {{3,1},{1,3},{1,1}};
        System.out.println(numberOfPairs(points));
    }
}
