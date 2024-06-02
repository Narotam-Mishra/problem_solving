
// Problem link - https://leetcode.com/problems/largest-perimeter-triangle/description/

package Basic_problems;

import java.util.Arrays;

public class FindLargestPerimeterTriangle {
    public static int largestPerimeter(int[] nums) {
        // Step 1: Sort the array in descending order
        Arrays.sort(nums);

        // Step 2: Iterate through the array and check for valid triangles
        for (int i = nums.length - 1; i >= 2; i--) {
            // Pick last three consecutive elements
            int a = nums[i];
            int b = nums[i - 1];
            int c = nums[i - 2];

            // Step 3: Check the triangle inequality theorem
            if (a < b + c) {
                return a + b + c;
            }
        }

        // Step 4: If no valid triangle is found, return 0
        return 0;
    }

    public static void main(String[] args) {
        // int[] nums = {2, 1, 2};

        int[] nums = {1, 2, 1, 10};
        System.out.println(largestPerimeter(nums));
    }
}
