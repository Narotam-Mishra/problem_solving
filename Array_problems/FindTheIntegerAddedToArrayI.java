
// Problem link - https://leetcode.com/problems/find-the-integer-added-to-array-i/description/?envType=problem-list-v2&envId=array

package Array_problems;

public class FindTheIntegerAddedToArrayI {
    public static int addedInteger(int[] nums1, int[] nums2) {
        // step 1: assume the first element is the minimum initially
        int min1 = nums1[0], min2 = nums2[0];

        // step 2: find the actual minimum value in nums1
        for(int num : nums1){
            min1 = Math.min(min1, num);
        }

        // step 3: find the actual minimum value in nums2
        for(int num : nums2){
            min2 = Math.min(min2, num);
        }

        // step 4 - retun the difference between min2 and min1 is the added integer `x`
        return min2 - min1;
    }

    public static void main(String[] args) {
        // int[] nums = {2,6,4}, nums2 = {9,7,5};

        // int[] nums = {10}, nums2 = {5};

        int[] nums = {1,1,1,1}, nums2 = {1,1,1,1};
        System.out.println(addedInteger(nums, nums2));
    }
}
