
// Problem link - https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-i/?envType=daily-question&envId=2026-06-02

package GreedyAlgorithms_problems;

public class EarliestFinishTimeForLandAndWaterRidesI {
    public int earliestFinishTime(int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDuration) {
        int n = landStartTime.length;
        int m = waterStartTime.length;

        // keep track of final result in `res`
        int res = Integer.MAX_VALUE;

        // step 1 - iterate of over every possible pair of (i,j)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // order 1 - land ride i first then water ride j
                // step 2 - Board land ride i at its opening time, finish at:
                int finishLand = landStartTime[i] + landDuration[i];

                // step 3 - after finishing land ride, water ride can only start
                int waterBegin = Math.max(finishLand, waterStartTime[j]);

                // step 4 - water ride finishes at:
                int ord1 = waterBegin + waterDuration[j];

                // order 2 - water ride j first then land ride i
                // step 5 - board water ride j at its opening time, finish at:
                int finishWater = waterStartTime[j] + waterDuration[j];

                // step 6 - after finishing water ride, land ride can only start
                int landBegin = Math.max(finishWater, landStartTime[i]);

                // step 7 - land ride finishes at:
                int ord2 = landBegin + landDuration[i];

                // step 8 - pick the earliest possible time
                int earliestTime = Math.min(ord1, ord2);

                // step 9 - update final result
                res = Math.min(res, earliestTime);
            }
        }

        // step 10 - return final result, `res`
        return res;
    }

    public static void main(String[] args) {
        int[] landStartTime = {2,8}, landDuration = {4,1};
        int[] waterStartTime = {6}, waterDuration = {3};
        EarliestFinishTimeForLandAndWaterRidesI obj = new EarliestFinishTimeForLandAndWaterRidesI();
        System.out.println(obj.earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration));
    }
}
