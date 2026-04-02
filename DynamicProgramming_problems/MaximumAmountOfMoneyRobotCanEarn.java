
// Problem link - https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/description/?envType=daily-question&envId=2026-04-02

package DynamicProgramming_problems;

public class MaximumAmountOfMoneyRobotCanEarn {
    // for memiozation
    int[][][] memo;

    int m, n;
    private int solveRec(int[][] coins, int i, int j, int np){
        // base case 1 - reached the end of cell
        if(i == m-1 && j == n-1){
            if(coins[i][j] < 0 && np > 0){
                // neutalise robber
                return 0;
            }
            return coins[i][j];
        }

        // base case 2
        if(i >= m || j >= n){
            return Integer.MIN_VALUE;
        }

        // if answer is already compute then return
        if(memo[i][j][np] != Integer.MIN_VALUE){
            return memo[i][j][np];
        }

        // case 1 - take current coins
        int take = coins[i][j] + Math.max(solveRec(coins,i+1,j,np), solveRec(coins,i,j+1,np));

        // case 2 - skip current cell
        int skip = Integer.MIN_VALUE;
        if(coins[i][j] < 0 && np > 0){
            int skipDown = solveRec(coins,i+1,j,np-1);
            int skipRight = solveRec(coins,i,j+1,np-1);

            skip = Math.max(skipDown, skipRight);
        }

        return memo[i][j][np] = Math.max(take, skip);
    }

    public int maximumAmount(int[][] coins) {
        // find size of row and column
        m = coins.length;
        n = coins[0].length;

        // step 1 - initialize memo
        memo = new int[m+1][n+1][3];
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<3; k++){
                    memo[i][j][k] = Integer.MIN_VALUE;
                }
            }
        }


        // step 2 - recursively compute and return result
        return solveRec(coins, 0, 0, 2);
    }

    public static void main(String[] args) {
        // int[][] coins = {{0,1,-1},{1,-2,3},{2,-3,4}};

        int[][] coins = {{10,10,10},{10,10,10}};
        MaximumAmountOfMoneyRobotCanEarn obj = new MaximumAmountOfMoneyRobotCanEarn();
        System.out.println(obj.maximumAmount(coins));
    }
}
