
// Problem link - https://leetcode.com/problems/trionic-array-ii/description/?envType=daily-question&envId=2026-02-04

package DynamicProgramming_problems;

public class TrionicArrayII {
    int n;
    long[][] memo;
    static final long NEG_INF = Long.MIN_VALUE / 2;

    private long solveRec(int i, int trend, int[] nums){
        // base case:
        if(i >= n){
            return trend == 3 ? 0 : NEG_INF;
        }

        // if answer is already computed then return
        if(memo[i][trend] != Long.MIN_VALUE){
            return memo[i][trend];
        }

        long take = NEG_INF;
        long skip = NEG_INF;

        // option 1 - skip (only in start state)
        if(trend == 0){
            skip = solveRec(i+1, 0, nums);
        }

        // option 2 - take current element
        if(trend == 3){
            take = nums[i];
        }

        if(i+1 < n){
            int curr = nums[i];
            int next = nums[i+1];

            // trend 0 -> 1
            if(trend == 0 && next > curr){
                take = Math.max(take, curr + solveRec(i+1, 1, nums));
            }

            // trend 1 -> 1 or 2
            else if(trend == 1){
                if(next > curr){
                    take = Math.max(take, curr + solveRec(i+1, 1, nums));
                }else if(next < curr){
                    take = Math.max(take, curr + solveRec(i+1, 2, nums));
                }
            }

            // trend 2 -> 2 or 3
            else if(trend == 2){
                if(next < curr){
                    take = Math.max(take, curr + solveRec(i+1, 2, nums));
                }else if(next > curr){
                    take = Math.max(take, curr + solveRec(i+1, 3, nums));
                }
            }

            // trend 3 -> 3
            else if(trend == 3 && next > curr){
                take = Math.max(take, curr + solveRec(i+1, 3, nums));
            }
        }

        return memo[i][trend] = Math.max(take, skip);
    }

    public long maxSumTrionic(int[] nums) {
        n = nums.length;
        memo = new long[n+1][4];

        // intialize memo
        for(int i=0; i<=n; i++){
            for(int j=0; j<4; j++){
                memo[i][j] = Long.MIN_VALUE;
            }
        }

        // step 1 - solve recursilvely and return result
        return solveRec(0, 0, nums);
    }

    public static void main(String[] args) {
        // int[] nums = {0,-2,-1,-3,0,2,-1};

        int[] nums = {1,4,2,7};
        TrionicArrayII solution = new TrionicArrayII();
        System.out.println(solution.maxSumTrionic(nums));
    }
}
