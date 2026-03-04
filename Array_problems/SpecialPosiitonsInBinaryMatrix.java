
// Problem link - https://leetcode.com/problems/special-positions-in-a-binary-matrix/description/?envType=daily-question&envId=2026-03-04

package Array_problems;

public class SpecialPosiitonsInBinaryMatrix {
    public static int numSpecial(int[][] mat) {
        // find row and column size
        int m = mat.length;
        int n = mat[0].length;

        // keep track row and column ones
        int[] rowOne = new int[m];
        int[] colOne = new int[n];

        // step 1 - iterate on matrix & count 1s
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    rowOne[i]++;
                    colOne[j]++;
                }
            }
        }

        // step 2 - find special posiiton
        int specialCount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1 && rowOne[i] == 1 && colOne[j] == 1) {
                    specialCount++;
                }
            }
        }

        // step 3 - return special count
        return specialCount;
    }

    public static void main(String[] args) {
        int[][] mat = {{1,0,0},{0,0,1},{1,0,0}};
        System.out.println(numSpecial(mat));
    }
}
