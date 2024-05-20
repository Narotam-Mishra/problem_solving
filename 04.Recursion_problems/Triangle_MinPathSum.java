
// Problem link - https://leetcode.com/problems/triangle/

package Recursion_problems;

import java.util.*;

public class Triangle_MinPathSum {
    public static List<List<Integer>> matrix;

    private static int findMinimumPatrhSumRec(int row, int col){
        // Base case: if row is last row then return current element
        if(row == matrix.size() - 1) return matrix.get(row).get(col);

        // Recursive Case : recursively calculate the minimum path sum
        return matrix.get(row).get(col) + Math.min(findMinimumPatrhSumRec(row+1, col), findMinimumPatrhSumRec(row+1, col+1));
    }
    public static int minimumTotal(List<List<Integer>> triangle) {
        matrix = triangle;
        return findMinimumPatrhSumRec(0, 0);
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