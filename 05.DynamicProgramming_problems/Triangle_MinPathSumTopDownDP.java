
// Problem link - https://leetcode.com/problems/triangle/

package DynamicProgramming_problems;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Triangle_MinPathSumTopDownDP {
    public static List<List<Integer>> matrix;
    public static int[][] dp = new int[205][205];

    private static int findMinimumPathSumTopDownDP(int row, int col){
        // Base case: if row is last row then return current element
        if(row == matrix.size() - 1) return matrix.get(row).get(col);

        // if dp[row][col] is already calculated then return dp[row][col]
        if(dp[row][col] != -1) return dp[row][col];

        // Recursive Case : recursively calculate the minimum path sum
        int ans = matrix.get(row).get(col) + Math.min(findMinimumPathSumTopDownDP(row+1, col), findMinimumPathSumTopDownDP(row+1, col+1));
        dp[row][col] = ans;
        return ans;
    }
    public static int minimumTotal(List<List<Integer>> triangle) {
        matrix = triangle;
        for(int i=0; i<205; i++){
            Arrays.fill(dp[i], -1);
        }
        return findMinimumPathSumTopDownDP(0, 0);
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
