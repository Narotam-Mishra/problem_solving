
// Problem link - https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/?envType=daily-question&envId=2025-11-26

package DynamicProgramming_problems;

public class PathInMatrixWhoseSumIsDivisibleByK {
    private static final int MOD = 1000000007;
    private static  int[][][] memo;
    
    private static int solve(int r, int c, int currSum, int k, int[][] grid, int m, int n) {
        // edge case:
        if (r >= m || c >= n) return 0;
        
        // base case:
        if (r == m - 1 && c == n - 1) {
            return (currSum + grid[m - 1][n - 1]) % k == 0 ? 1 : 0;
        }
        
        // if answer is already computed then return the answer
        if (memo[r][c][currSum] != -1) {
            return memo[r][c][currSum] % MOD;
        }
        
        // recursive case: recursively move down and right respectively
        int down = solve(r + 1, c, (currSum + grid[r][c]) % k, k, grid, m, n);
        int right = solve(r, c + 1, (currSum + grid[r][c]) % k, k, grid, m, n);
        
        return memo[r][c][currSum] = (down + right) % MOD;
    }
    
    public static  int numberOfPaths(int[][] grid, int k) {
        // find rows and columns size of grid
        int m = grid.length;
        int n = grid[0].length;
        
        memo = new int[m][n][k];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int l = 0; l < k; l++) {
                    memo[i][j][l] = -1;
                }
            }
        }
        
        // step 1 - solve the problem recursively
        return solve(0, 0, 0, k, grid, m, n);
    }

    public static void main(String[] args) {
        // int[][] grid  = {{5,2,4},{3,0,5},{0,7,2}}; 

        int[][] grid  = {{7,3,4,9},{2,3,6,2},{2,3,7,0}}; 
        int k = 1;
        System.out.println(numberOfPaths(grid, k));
    }
}
