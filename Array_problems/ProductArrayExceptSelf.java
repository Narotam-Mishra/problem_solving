
// Problem link : https://leetcode.com/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=top-100-liked

package Array_problems;

import java.util.Arrays;

public class ProductArrayExceptSelf {
    public static int[] productExceptSelf(int[] nums) {
        int len = nums.length;
        int[] ansArr = new int[len];
        Arrays.fill(ansArr, 1);

        // compute left product
        int leftProduct = 1;
        for(int i=0; i<len; i++){
            ansArr[i] = leftProduct;
            leftProduct *= nums[i];
        }

        // compute right product and combine it with right product
        int rightProduct = 1;
        for(int i=len-1; i>=0; i--){
            ansArr[i] *= rightProduct;
            rightProduct *= nums[i];
        }
        // return answer product array 'ansArrs'
        return ansArr;
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4};
        int[] ans = productExceptSelf(arr);
        System.out.println(Arrays.toString(ans));
    }
}