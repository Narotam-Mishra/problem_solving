
// Problem link - https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/?envType=daily-question&envId=2025-09-02

package NumberTheory_Problems;

public class FindNumberOfWaysToPlacePeopleI {
    public static int numberOfPairs(int[][] points) {
        int n = points.length;

        // store count of valid points
        int count = 0;

        // step 1 - try every pair of points
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // skip same points
                if (i == j)
                    continue;

                // extract co-ordinate points
                int[] A = points[i];
                int[] B = points[j];

                // step 2 - check first condition : if A is on upper left of B
                // A is on upper left if A.x <= B.x and A.y >= b.y
                if (A[0] <= B[0] && A[1] >= B[1]) {
                    // step 3 - check second condition : there is no points inside rectangle
                    boolean hasPointsInside = false;

                    // check every other possible points to see if it lies in the rectangle
                    for (int k = 0; k < n; k++) {
                        // skip same points
                        if (k == i || k == j)
                            continue;

                        // extract co-ordinate points
                        int[] point = points[k];
                        int x = point[0];
                        int y = point[1];

                        // check if this point lies inside rectangle or not
                        if (x >= A[0] && x <= B[0] && y >= B[1] && y <= A[1]) {
                            hasPointsInside = true;
                            break;
                        }
                    }

                    // step 4 - if no points lies inside rectangle
                    if (!hasPointsInside) {
                        // this is valid pair, so increment count
                        count++;
                    }
                }
            }
        }

        // step 5 - return valid count
        return count;
    }

    public static void main(String[] args) {
        // int[][] points = {{1,1},{2,2},{3,3}};

        // int[][] points = {{6,2},{4,4},{2,6}};

        int[][] points = {{3,1},{1,3},{1,1}};
        System.out.println(numberOfPairs(points));
    }
}
