
// Problem link - https://leetcode.com/problems/rotating-the-box/description/?envType=daily-question&envId=2026-05-06

package Array_problems;

import java.util.Arrays;

public class RotatingTheBox {
    public char[][] rotateTheBox(char[][] boxGrid) {
        // find row and column size
        int m = boxGrid.length;
        int n = boxGrid[0].length;

        // step 1 - find transpose of a given boxGrid
        char[][] res = new char[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[i][j] = boxGrid[j][i];
            }
        }

        // step 2 - for 90 degree rotation, reverse each row
        for (char[] row : res) {
            int left = 0;
            int right = row.length - 1;

            while (left < right) {
                char temp = row[left];
                row[left] = row[right];
                row[right] = temp;
                left++;
                right--;
            }
        }

        // step 3 - apply gravity effect
        for (int j = 0; j < m; j++) {
            for (int i = n - 1; i >= 0; i--) {
                if (res[i][j] == '.') {
                    // if it is space then shift stone
                    int stoneRow = -1;

                    for (int k = i - 1; k >= 0; k--) {
                        if (res[k][j] == '*') {
                            // incase of obstacle break
                            break;
                        } else if (res[k][j] == '#') {
                            stoneRow = k;
                            break;
                        }
                    }

                    if (stoneRow != -1) {
                        res[i][j] = '#';
                        res[stoneRow][j] = '.';
                    }
                }
            }
        }

        // step 4 - return final result, res
        return res;
    }

    public static void main(String[] args) {
        char[][] boxGrid = {{'#','.','#'}};
        RotatingTheBox obj = new RotatingTheBox();
        char[][] res = obj.rotateTheBox(boxGrid);
        System.out.println(Arrays.deepToString(res));
    }
}
