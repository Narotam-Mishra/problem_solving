
// Problem link - https://leetcode.com/problems/first-missing-positive/?envType=problem-list-v2&envId=array

package Array_problems;

public class FirstMissingPositive {
    public static int firstMissingPositive(int[] nums) {
        int n = nums.length;

        // step 1 - place each number at its correct position
        for(int i=0; i<n; i++){
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]){
                // swap nums[i] with its correct index
                int correctIndex = nums[i] - 1;
                int temp = nums[correctIndex];
                nums[correctIndex] = nums[i];
                nums[i] = temp;
            }
        }

        // step 2 - find the first missing number
        for(int i=0; i<n; i++){
            if(nums[i] != i+1){
                return i+1;
            }
        }

        // step 3 - if all numbers 1 to n are present, return n+1
        return n+1;
    }

    public static void main(String[] args) {
        // int[] nums = {1, 2, 0};

        // int[] nums = {3, 4, -1, 1};

        int[] nums = {7,8,9,11,12};
        System.out.println(firstMissingPositive(nums));
    }
}