
// Problem link - https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle/description/?envType=daily-question&envId=2025-08-26

package Array_problems;

public class MaximumAreaOfLongestDiagonalRectangle {
    public static int areaOfMaxDiagonal(int[][] dimensions) {
        // keep track of maximum area
        int maxArea = 0;

        // keep track of longest digonal
        long maxDigonalSqr = 0;

        // step 1 - iterate on each reactangle's dimesion
        for(int[] dimesion : dimensions){
            // step 2 - extract length and breadth from dimension
            int l = dimesion[0];
            int b = dimesion[1];

            // step 3 - calculate diagonal
            long currDiagonalSqr = (long) l * l + (long) b * b;

            // step 4 - calculate rectangle's area with current dimesion
            int area = l * b;

            // step 5 - compare current diagonal with maximum diagonal found so far
            if(currDiagonalSqr > maxDigonalSqr){
                // case 1 - found rectangle with longer diagonal
                // update maximum area and maximum diagonal in this case
                maxArea = area;
                maxDigonalSqr = currDiagonalSqr;
            }else if(currDiagonalSqr == maxDigonalSqr){
                // case 2 - found a rectangle with same diagonal length as current maximum
                // using epsilon comparison for double precision equality
                // keep the maximum area among all
                maxArea = Math.max(maxArea, area);
            }
        }

        // step 6 - return maximum area of longest diagonal
        return maxArea;
    }

    public static void main(String[] args) {
        // int[][] dimensions = {{9,3}, {8,6}};

        int[][] dimensions = {{3,4}, {4,3}};
        System.out.println(areaOfMaxDiagonal(dimensions));
    }
}
