package Array_problems;

import java.util.Arrays;

public class SearchIn2DArray {

    public static void main(String[] args) {
        int[][] arr = {
                { 23, 4, 11 },
                { 7, 3, 13 },
                { 77, 91, 21, 33 },
                { 19, 27, 67 }
        };
        int key = 21;
        int ans[] = search2DArray(arr, key);
        System.out.println(Arrays.toString(ans));
    }

    public static int[] search2DArray(int[][] arr, int key) {
        for (int r = 0; r < arr.length; r++) {
            for (int c = 0; c < arr[r].length; c++) {
                if (arr[r][c] == key) {
                    return new int[] { r, c };
                }
            }
        }
        return new int[0];
    }
}
