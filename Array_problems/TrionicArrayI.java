
// Problem link - https://leetcode.com/problems/trionic-array-i/description/?envType=daily-question&envId=2026-02-03

package Array_problems;

public class TrionicArrayI {
    public static boolean isTrionic(int[] nums) {
        // find size of `nums`
        int n = nums.length;

        // keep track of each num of nums
        int i = 0;

        // step 1 - check increasing sequence
        while(i+1 < n && nums[i] < nums[i+1]){
            i++;
        }

        // step 2 - check if we stuck at start or reached end
        if(i == 0 || i == n - 1){
            return false;
        }

        // step 3 - check decresing sequence
        while(i+1 < n && nums[i] > nums[i+1]){
            i++;
        }

        // step 4 - check if we have reached end
        if(i == n-1){
            return false;
        }

        // step 5 - check incresing sequence again
        while(i+1 < n && nums[i] < nums[i+1]){
            i++;
        }

        // step 6 - return true if we have reached end
        // otherwise return false
        return i == n-1;
    }

    public static void main(String[] args) {
        // int[] nums = {1,3,5,4,2,6};

        int[] nums = {2,1,3};
        System.out.println(isTrionic(nums));
    }
}
