
// Problem link - https://leetcode.com/problems/min-max-game/description/?envType=problem-list-v2&envId=array

package Array_problems;

public class MinMaxGame {
    public static int minMaxGame(int[] nums) {
        // store current length of `nums` array
        int currLen = nums.length;
        
        // step 1 - repeat the process until `nums` array length greater than 1
        while (currLen > 1) {
            // step 2 - since length is always power of 2, division is exact
            int newLen = currLen / 2;

            // step 3 - process each pair and build new array as per given condition
            for (int i = 0; i < newLen; i++) {
                // first element of pair
                int leftNum = nums[2 * i];

                // second element of pair
                int rightNum = nums[2 * i + 1];

                // step 4 - apply min-max rule based on index
                if (i % 2 == 0) {
                    nums[i] = Math.min(leftNum, rightNum);
                } else {
                    nums[i] = Math.max(leftNum, rightNum);
                }
            }

            // step 5 - shrink array by its new length `newLen`
            currLen = newLen;
        }

        // step 6 - return last number
        return nums[0];
    }

    public static void main(String[] args) {
        // int[] nums = {1,3,5,2,4,8,2,2};

        int[] nums = {3};
        System.out.println(minMaxGame(nums));
    }
}