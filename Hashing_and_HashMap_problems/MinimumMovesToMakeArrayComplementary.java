
// Problem link - https://leetcode.com/problems/minimum-moves-to-make-array-complementary/

package Hashing_and_HashMap_problems;

public class MinimumMovesToMakeArrayComplementary {
    public int minMoves(int[] nums, int limit) {
        int n = nums.length;

        // step 1 - using difference array technique (DAT).
        // diff[sum] will finally store the total moves needed
        // to make every mirror pair equal to this target sum.
        int[] diff = new int[2*limit+2];

        // step 2 - process every mirror pair.
        for(int i=0; i<n/2; i++){
            int a = nums[i];
            int b = nums[n-1-i];

            // for this pair, these are the target sums possible in exactly 1
            // move. minimum one-move sum: change bigger/smaller pair value
            // to 1. maximum one-move sum: change bigger/smaller pair value to
            // limit.
            int minVal = Math.min(a,b) + 1;
            int maxVal = Math.max(a,b) + limit;

            // step 3 - initially assume this pair needs 2 moves for every
            // target sum. valid target sums are from 2 to 2 * limit.
            diff[2] += 2;
            diff[2*limit+1] -= 2;

            // step 4 - for sums in [minVal, maxVal], this pair needs only 1
            // move. since we already added 2 moves, subtract 1 from this range.
            diff[minVal] += (-1);
            diff[maxVal+1] -= (-1);

            // step 5 - for the exact current sum a + b, this pair needs 0
            // moves. since this sum is already in the one-move range, subtract
            // 1 more.
            diff[a+b] += (-1);
            diff[a+b+1] -= (-1);
        }

        // keep track of final result in `res`
        int res = Integer.MAX_VALUE;

        // step 6 - convert the difference array into actual move counts using
        // prefix sum.
        for(int sum=2; sum<=2*limit; sum++){
            diff[sum] += diff[sum-1];

            // update answer with the minimum moves needed for this target sum.
            res = Math.min(res, diff[sum]);
        }

        // step 7 - return final minimum moves
        return res;
    }

    public static void main(String[] args) {
        int[] nums = {1,2,4,3};
        int limit = 4;
        MinimumMovesToMakeArrayComplementary obj = new MinimumMovesToMakeArrayComplementary();
        System.out.println(obj.minMoves(nums, limit));
    }
}
