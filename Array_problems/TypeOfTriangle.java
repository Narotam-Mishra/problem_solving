
// Problem link - https://leetcode.com/problems/type-of-triangle/?envType=problem-list-v2&envId=array

package Array_problems;

public class TypeOfTriangle {
    public static String triangleType(int[] nums) {
        // step 1 - extract three sides from `nums` array
        int a = nums[0], b = nums[1], c = nums[2];

        // step 2 - check condition for valid traingle
        if (a + b <= c || b + c <= a || c + a <= b) {
            // return as it is invalid case for triangle
            return "none";
        }

        // step 3 - check condition for each type of triangle and return its type
        if (a == b && b == c) {
            return "equilateral";
        } else if (a == b || b == c || c == a) {
            return "isosceles";
        } else {
            return "scalene";
        }
    }

    public static void main(String[] args) {
        // int[] nums = {3,3,3};

        // int[] nums = {3,4,5};

        int[] nums = {3,4,3};
        System.out.println(triangleType(nums));
    }
}