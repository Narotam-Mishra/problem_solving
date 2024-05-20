
// Problem link - https://leetcode.com/problems/triangle/

package DynamicProgramming_problems;

import java.util.*;

public class Triangle_MinPathSumBottomUpDP {
    public static List<List<Integer>> matrix;
    public static int[][] dp;

    private static int findMinimumPathSumBottomUpDP(){
        dp = new int[205][205];

        // n ---> total row
        int n = matrix.size();

        // Base case:
        for(int i=0; i<matrix.get(n-1).size(); i++){
            dp[n-1][i] = matrix.get(n-1).get(i);
        }

        // fill the 2-D DP in Bottom Up DP
        for(int row = n-2; row >= 0; row--){
            for(int col=0; col < matrix.get(row).size(); col++){
                dp[row][col] = matrix.get(row).get(col) + Math.min(dp[row+1][col], dp[row+1][col+1]);
            }
        }
        return dp[0][0];
    }
    public static int minimumTotal(List<List<Integer>> triangle) {
        matrix = triangle;
        return findMinimumPathSumBottomUpDP();
    }

    public static void main(String[] args) {
        List<List<Integer>> triangle = new ArrayList<>();
        triangle.add(new ArrayList<>(List.of(2)));
        triangle.add(new ArrayList<>(List.of(3, 4)));
        triangle.add(new ArrayList<>(List.of(6, 5, 7)));
        triangle.add(new ArrayList<>(List.of(4, 1, 8, 3)));
        int ans = minimumTotal(triangle);
        System.out.println(ans);
    }
}
