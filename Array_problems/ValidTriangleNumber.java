
// Problem link - https://leetcode.com/problems/valid-triangle-number/?envType=daily-question&envId=2025-09-26

package Array_problems;

import java.util.Arrays;

public class ValidTriangleNumber {
    public static int triangleNumber(int[] nums) {
        // store the count of valid triangle's triplets
        int count = 0;
        int n = nums.length;

        // step 1 - sort the array
        Arrays.sort(nums);

        // step 2 - fix the largest side and find pairs for the other two sides
        // we iterate from the end because after sorting, the largest element
        // will be at the end, and we want to fix it as the longest side
        for(int i=n-1; i>=2; i--){
            // step 3 - using two pointers
            // left pointer, `s` starts from beginning, right, `e` from i-1
            int s = 0, e = i-1;

            // Triangle inequality: For three sides a, b, c (where c is largest)
            // a + b > c is the only condition we need to check
            // (since a + c > b and b + c > a are automatically satisfied when c is largest)
            while(s < e){
                // step 4 - check if current triplet forms a valid triangle
                if(nums[s] + nums[e] > nums[i]){
                    // if nums[s] + nums[e] > nums[k], then all pairs
                    // (s, s+1), (s, s+2), ..., (s, e)
                    // will also satisfy the condition with nums[i] as nums is sorted
                    count += (e - s);
                    e--;
                }else{
                    // if sum is not greater than nums[i], we need a larger sum
                    // so move left pointer rightward to get larger values
                    s++;
                }
            }
        }

        // step 5 - return final count
        return count;
    }

    public static void main(String[] args) {
        // int[] nums = {2,2,3,4};

        int[] nums = {4,2,3,4};
        System.out.println(triangleNumber(nums));
    }
}
