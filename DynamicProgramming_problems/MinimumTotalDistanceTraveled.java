
// Problem link - https://leetcode.com/problems/minimum-total-distance-traveled/description/?envType=daily-question&envId=2026-04-14

package DynamicProgramming_problems;

import java.util.*;

public class MinimumTotalDistanceTraveled {
    private long[][] memo;

    private long solveRec(int ri, int fj, List<Integer> robot, List<Integer> positions){
        // base case
        if (ri >= robot.size()) return 0;
        if (fj >= positions.size()) return (long) 1e12;

        // if answer is already computed, return it
        if (memo[ri][fj] != -1) return memo[ri][fj];

        // recursive case: take current factory or skip it
        long takeCurrFactory = Math.abs(robot.get(ri) - positions.get(fj))
                + solveRec(ri + 1, fj + 1, robot, positions);
        long skipCurrFactory = solveRec(ri, fj + 1, robot, positions);

        // return minimum total distance travelled
        return memo[ri][fj] = Math.min(takeCurrFactory, skipCurrFactory);
    }

    public long minimumTotalDistance(List<Integer> robot, int[][] factory) {
        // step 1 - sort robot and factory for efficiency
        Collections.sort(robot);
        Arrays.sort(factory, (a, b) -> a[0] - b[0]);

        // step 2 - expand factory positions according to limit
        List<Integer> positions = new ArrayList<>();
        for (int[] f : factory) {
            int pos = f[0];
            int limit = f[1];
            for (int j = 0; j < limit; j++) {
                positions.add(pos);
            }
        }

        // memoization table
        int m = robot.size();
        int n = positions.size();
        memo = new long[m + 1][n + 1];
        for (long[] row : memo) Arrays.fill(row, -1L);

        // step 3 - solve recursively and return
        return solveRec(0, 0, robot, positions);
    }

    public static void main(String[] args) {
        MinimumTotalDistanceTraveled obj = new MinimumTotalDistanceTraveled();
        // List<Integer> robot = Arrays.asList(0,4,6);
        // int[][] factory = {{2,2},{6,2}};

        List<Integer> robot = Arrays.asList(1,-1);
        int[][] factory = {{-2,1},{2,1}};
        System.out.println(obj.minimumTotalDistance(robot, factory));
    }
}
