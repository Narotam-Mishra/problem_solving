
// Problem link - https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/?envType=daily-question&envId=2025-11-17

package Array_problems;

public class CheckIfAllOnesAreAtLeastLengthKPlacesAway {
    public static  boolean kLengthApart(int[] nums, int k) {
        // find size of input array, nums
        int n = nums.length;

        // keep track of last 1 index
        int lastOne = -(k + 1);

        // step 1 - iterate through nums
        for (int i = 0; i < n; i++) {
            // step 2 - check if current element and find gap
            if (nums[i] == 1) {
                // gap of current 1 from last one visited should be atleast k
                if (i - lastOne - 1 < k) {
                    return false;
                }

                // step 3 - update last 1 index
                lastOne = i;
            }
        }

        // step 4 - return true, if everything works fine
        return true;
    }

    public static void main(String[] args) {
        // int[] nums = {1,0,0,0,1,0,0,1};
        // int k = 2;

        int[] nums = {1,0,0,1,0,1};
        int k = 2;
        System.out.println(kLengthApart(nums, k));
    }
}
