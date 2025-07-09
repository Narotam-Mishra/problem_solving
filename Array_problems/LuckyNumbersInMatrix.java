
// Problem link - https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/?envType=problem-list-v2&envId=array

package Array_problems;

import java.util.*;

public class LuckyNumbersInMatrix {
    public static List<Integer> luckyNumbers(int[][] matrix) {
        int n = matrix.length;

        // store lucky numbers in `luckyNums`
        List<Integer> luckyNums = new ArrayList<>();

        // step 1 - loop through each row
        for (int i = 0; i < n; i++) {
            int[] row = matrix[i];
            int minVal = row[0];
            int minIndex = 0;

            // step 2 - check minimum element in current row
            for (int j = 1; j < row.length; j++) {
                if (row[j] < minVal) {
                    minVal = row[j];
                    minIndex = j;
                }
            }

            // step 3 - check if this min value is also the maximum in its column
            boolean isMaxInCol = true;
            for (int k = 0; k < n; k++) {
                if (matrix[k][minIndex] > minVal) {
                    isMaxInCol = false;
                    break;
                }
            }

            // step 4 - if it is the maximum in column, it's a lucky number
            if (isMaxInCol) {
                luckyNums.add(minVal);
            }
        }

        // step 5 - return lucky number array `luckyNums`
        return luckyNums;
    }

    public static void main(String[] args) {
        // int[][] matrix = {{3,7,8},{9,11,13},{15,16,17}};

        // int[][] matrix = {{1,10,4,2},{9,3,8,7},{15,16,17,12}};

        int[][] matrix = {{7,8}, {1,2}};
        System.out.println(luckyNumbers(matrix));
    }
}