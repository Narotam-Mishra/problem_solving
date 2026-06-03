
// Problem link - https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-ii/description/?envType=daily-question&envId=2026-06-03

package Array_problems;

public class EarliestFinishTimeForLandAndWaterRidesII {
    // helper function to compute the earliest time to finish one ride from the
    // first category
    private int findFinishTime(int[] startTime1, int[] duration1, int[] startTime2, int[] duration2) {

        // step 1 - choose the ride from the first category that finishes earliest.
        // each ride i can start no earlier than startTime1[i] and finishes at
        // startTime1[i] + duration1[i] if taken immediately.
        int finish1 = Integer.MAX_VALUE;
        for (int i = 0; i < startTime1.length; i++) {
            finish1 = Math.min(finish1, startTime1[i] + duration1[i]);
        }

        // step 2 - after finishing the first ride at finish1, choose the second ride
        // that can start no earlier than max(finish1, startTime2[i]) and finishes at
        // that start time plus duration2[i].
        int finish2 = Integer.MAX_VALUE;
        for (int i = 0; i < startTime2.length; i++) {
            finish2 = Math.min(finish2, Math.max(finish1, startTime2[i]) + duration2[i]);
        }

        // return final finish time, `finish2`
        return finish2;
    }

    public int earliestFinishTime(int[] landStartTime, int[] landDuration, int[] waterStartTime, int[] waterDuration) {
        // step 1 - evaluate both possible orders: land first then water, or water first
        // then land.
        int res1 = findFinishTime(landStartTime, landDuration, waterStartTime, waterDuration);
        int res2 = findFinishTime(waterStartTime, waterDuration, landStartTime, landDuration);

        // step 2 - return the earliest overall finish time.
        return Math.min(res1, res2);
    }

    public static void main(String[] args) {
        int[] landStartTime = {2,8}, landDuration = {4,1};
        int[] waterStartTime = {6}, waterDuration = {3};
        EarliestFinishTimeForLandAndWaterRidesII obj = new EarliestFinishTimeForLandAndWaterRidesII();
        System.out.println(obj.earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration));
    }
}
