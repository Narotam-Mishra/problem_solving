
// Problem link - https://leetcode.com/problems/separate-the-digits-in-an-array/?envType=daily-question&envId=2026-05-11

package Array_problems;

import java.util.Arrays;

public class SeparateDigitsInArray {
    public int[] separateDigits(int[] nums) {
        // step 1 - calculate total digits
        int totalDigits = 0;
        for (int num : nums) {
            totalDigits += String.valueOf(num).length();
        }

        // keep track of final result in `res`
        int[] res = new int[totalDigits];

        // keep track of index
        int idx = 0;

        // step 2 - iterate on each number of nums
        for(int num : nums){
            // step 3 - convert each num to string
            String str = String.valueOf(num);

            // step 4 - extract each digit from num
            for(char ch : str.toCharArray()){
                // store in `res`
                res[idx++] = ch - '0';
            }
        }

        // step 5 - return final result, `res`
        return res;
    }

    public static void main(String[] args) {
        int[] nums = {13,25,83,77};
        SeparateDigitsInArray obj = new SeparateDigitsInArray();
        int[] res = obj.separateDigits(nums);
        System.out.println(Arrays.toString(res));
    }
}
