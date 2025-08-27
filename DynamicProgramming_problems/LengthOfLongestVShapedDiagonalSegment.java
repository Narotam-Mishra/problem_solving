package DynamicProgramming_problems;

public class LengthOfLongestVShapedDiagonalSegment {
    static int m, n;
    private static int[][] directions = { { 1, 1 }, { 1, -1 }, { -1, -1 }, { -1, 1 } };

    // 4-D DP table: dp[i][j][direction][canTurn]
    // Using -1 to indicate "not computed"
    private static int[][][][] dp;

    private static int solveRec(int i, int j, int d, boolean canTurn, int val, int[][] grid) {
        // calculate new position based on current direction
        int new_i = i + directions[d][0];
        int new_j = j + directions[d][1];

        // boundary check and value validation
        // if out of bounds OR value doesn't match expected alternating pattern
        if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n || grid[new_i][new_j] != val) {
            // so return 0
            return 0;
        }

        // check memoization table and return precomputed value
        int canTurnInt = canTurn ? 1 : 0;
        if (dp[new_i][new_j][d][canTurnInt] != -1) {
            return dp[new_i][new_j][d][canTurnInt];
        }

        int ans = 0;

        // Case 1: continue moving in same direction
        int keepMoving = 1 + solveRec(new_i, new_j, d, canTurn, val == 2 ? 0 : 2, grid);
        ans = Math.max(ans, keepMoving);

        // Case 2: Make a clockwise turn (only if we haven't turned yet)
        if (canTurn) {
            // calculate new direction: clockwise turn means (d + 1) % 4
            int newDirection = (d + 1) % 4;

            // try turning: move to new position, new direction, can't turn again
            int turnAndMove = Math.max(keepMoving, 1 + solveRec(new_i, new_j, newDirection, false, val == 2 ? 0 : 2, grid));
            ans = Math.max(ans, turnAndMove);
        }

        // memoize and return
        dp[new_i][new_j][d][canTurnInt] = ans;
        return ans;
    }

    public static int lenOfVDiagonal(int[][] grid) {
        // find row and column size
        m = grid.length;
        n = grid[0].length;

        // step 1 - initialize DP table with -1 (meaning not computed)
        dp = new int[m][n][4][2];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int d = 0; d < 4; d++) {
                    for (int turn = 0; turn < 2; turn++) {
                        dp[i][j][d][turn] = -1;
                    }
                }
            }
        }

        // store longest V shape length in `maxVLen`
        int maxVLen = 0;

        // step 2 - try every cell as potential starting point
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // V-diagonal must start with value 1
                if (grid[i][j] == 1) {
                    // step 3 - try all 4 diagonal directions as initial direction
                    for (int d = 0; d <= 3; d++) {
                        // step 4 - start recursion : 1 (current cell) + maximum extension
                        maxVLen = Math.max(maxVLen, 1 + solveRec(i, j, d, true, 2, grid));
                    }
                }
            }
        }

        // step 5 - return longest V-Shape length
        return maxVLen;
    }

    public static void main(String[] args) {
        // int[][] grid = {{2,2,1,2,2},{2,0,2,2,0},{2,0,1,1,0},{1,0,2,2,2},{2,0,0,2,2}};

        int[][] grid = {{2,2,2,2,2},{2,0,2,2,0},{2,0,1,1,0},{1,0,2,2,2},{2,0,0,2,2}};
        System.out.println(lenOfVDiagonal(grid));
    }
}
