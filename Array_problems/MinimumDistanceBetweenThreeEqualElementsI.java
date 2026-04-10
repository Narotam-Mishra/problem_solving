
// Problem link - https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/description/?envType=daily-question&envId=2026-04-10

package Array_problems;

public class MinimumDistanceBetweenThreeEqualElementsI {
    public int minimumDistance(int[] nums) {
        // keep track of minimum possible distance
        int minDistance = Integer.MAX_VALUE;

        // step 1 - try every combination of 3 distinct indices
        int n = nums.length;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    // step 2 - check if it form a good tuple
                    if (nums[i] == nums[j] && nums[j] == nums[k]) {
                        // step 3 - compute distance
                        int dist = Math.abs(i - j) + Math.abs(j - k) + Math.abs(k - i);

                        // step 4 - update minimum distance
                        minDistance = Math.min(minDistance, dist);
                    }
                }
            }
        }

        // step 5 - return final minimum distance
        return minDistance == Integer.MAX_VALUE? -1 : minDistance;
    }

    public static void main(String[] args) {
        // int[] nums = {1,2,1,1,3};

        int[] nums = {1,1,2,3,2,1,2};
        MinimumDistanceBetweenThreeEqualElementsI obj = new MinimumDistanceBetweenThreeEqualElementsI();
        System.out.println(obj.minimumDistance(nums));
    }
}
