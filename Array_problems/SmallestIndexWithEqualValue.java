
// Problem link - https://leetcode.com/problems/smallest-index-with-equal-value/?envType=problem-list-v2&envId=array

package Array_problems;

public class SmallestIndexWithEqualValue {
    public static int smallestEqual(int[] nums) {
        // step 1 - iterate on `nums` array
        for(int i=0; i<nums.length; i++){
            // step 2 - check the condition, `i mod 10 == nums[i]`
            if(i % 10 == nums[i]){
                // step 3 - return index `i` immdiately
                return i;
            }
        }

        // step 4 - otherwise retun `-1` if given condition doesn't satisfy
        return -1;
    }

    public static void main(String[] args) {
        // int[] nums = {0,1,2};

        // int[] nums = {4,3,2,1};

        int[] nums = {1,2,3,4,5,6,7,8,9,0};
        System.out.println(smallestEqual(nums));
    }
}