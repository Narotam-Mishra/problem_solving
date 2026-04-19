
// Problem link - https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/?envType=daily-question&envId=2026-04-19

package Array_problems;

public class MaximumDistanceBetweenPairOfValues {
    public int maxDistance(int[] nums1, int[] nums2) {
        // get the sizes of both arrays
        int m = nums1.length;
        int n = nums2.length;

        // keep track of maximum distance
        int maxD = 0;

        // using two pointers, one for each array
        int i = 0, j = 0;

        // step 1 - iterate through both arrays using the two-pointer technique
        while (i < m && j < n) {
            // step 2 - check If nums1[i] > nums2[j], we need to move the
            // pointer for nums1 forward because we can't use this i for future
            // j's as the condition nums1[i] <= nums2[j] won't hold
            if (nums1[i] > nums2[j]) {
                i++;
            } else {
                // step 3 - check If nums1[i] <= nums2[j], calculate the
                // distance j - i and update maxD if larger
                maxD = Math.max(maxD, j - i);
                // step 4 - move the pointer for nums2 forward to check for
                // larger distances with the same i
                j++;
            }
        }
        // step 5 - return the maximum distance found
        return maxD == 0 ? 0 : maxD;
    }

    public static void main(String[] args) {
        MaximumDistanceBetweenPairOfValues obj = new MaximumDistanceBetweenPairOfValues();
        int[] nums1 = {55,30,5,4,2}, nums2 = {100,20,10,10,5};
        System.out.println(obj.maxDistance(nums1, nums2));
    }
}
