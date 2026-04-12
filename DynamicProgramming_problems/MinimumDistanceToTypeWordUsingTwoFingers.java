
// Problem link - https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers/description/?envType=daily-question&envId=2026-04-12

package DynamicProgramming_problems;

public class MinimumDistanceToTypeWordUsingTwoFingers {
    int[][][][][] dp = new int[301][7][7][7][7];

    // Get (row, col) for character
    int[] getCoordinate(char ch) {
        int pos = ch - 'A';
        return new int[]{pos / 6, pos % 6};
    }

    // Manhattan distance
    int getDistance(int x1, int y1, int x2, int y2) {
        return Math.abs(x1 - x2) + Math.abs(y1 - y2);
    }

    int solveRec(String word, int i, int x1, int y1, int x2, int y2) {
        if (i == word.length()) return 0;

        if (dp[i][x1 + 1][y1 + 1][x2 + 1][y2 + 1] != -1) {
            return dp[i][x1 + 1][y1 + 1][x2 + 1][y2 + 1];
        }

        int[] coord = getCoordinate(word.charAt(i));
        int x = coord[0], y = coord[1];

        // Case 1: both fingers not used
        if (x1 == -1 && y1 == -1 && x2 == -1 && y2 == -1) {
            return dp[i][x1 + 1][y1 + 1][x2 + 1][y2 + 1] =
                solveRec(word, i + 1, x, y, x2, y2);
        }

        // Case 2: second finger not used
        if (x2 == -1 && y2 == -1) {
            int moveF2 = solveRec(word, i + 1, x1, y1, x, y);

            int moveF1 = solveRec(word, i + 1, x, y, x2, y2)
                       + getDistance(x1, y1, x, y);

            return dp[i][x1 + 1][y1 + 1][x2 + 1][y2 + 1] =
                Math.min(moveF1, moveF2);
        }

        // Case 3: both fingers used
        int moveF1 = solveRec(word, i + 1, x, y, x2, y2)
                   + getDistance(x1, y1, x, y);

        int moveF2 = solveRec(word, i + 1, x1, y1, x, y)
                   + getDistance(x2, y2, x, y);

        return dp[i][x1 + 1][y1 + 1][x2 + 1][y2 + 1] =
            Math.min(moveF1, moveF2);
    }

    public int minimumDistance(String word) {
        // Initialize DP with -1
        for (int i = 0; i < 301; i++) {
            for (int a = 0; a < 7; a++) {
                for (int b = 0; b < 7; b++) {
                    for (int c = 0; c < 7; c++) {
                        for (int d = 0; d < 7; d++) {
                            dp[i][a][b][c][d] = -1;
                        }
                    }
                }
            }
        }

        return solveRec(word, 0, -1, -1, -1, -1);
    }

    public static void main(String[] args) {
        String word = "CAKE";
        MinimumDistanceToTypeWordUsingTwoFingers obj = new MinimumDistanceToTypeWordUsingTwoFingers();
        System.out.println(obj.minimumDistance(word));
    }
}
