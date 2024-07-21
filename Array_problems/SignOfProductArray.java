
// Problem link - https://leetcode.com/problems/sign-of-the-product-of-an-array/

package Array_problems;

public class SignOfProductArray {
    public static int arraySign(int[] nums) {
        int countNegatives = 0;
        for(int i=0; i<nums.length; i++){
            if(nums[i] == 0) return 0;
            else if(nums[i] < 0){
                countNegatives++;
            }
        }
        return countNegatives % 2 == 0 ? 1 : -1;
    }
    
    public static void main(String[] args) {
        // int[] arr = {-1, -2, -3, -4, 3, 2, 1};

        int[] arr = {1,5,0,2,-3};
        System.out.println(arraySign(arr));
    }
}