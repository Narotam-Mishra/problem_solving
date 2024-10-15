
// Problem link : https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/description/?envType=problem-list-v2&envId=bit-manipulation&status=TO_DO&difficulty=EASY

package BitMasking_Problems;

import java.util.*;

public class ConstructMinimumBitwiseArrayI {
    public static int[] minBitwiseArray(List<Integer> nums) {
        int[] res = new int[nums.size()];
        int id = 0;

        // iterate through each number in the nums array
        for(int num : nums){
            boolean found = false;

            // try values for ans[i] starting from 0 and upwards
            for(int i=0; i<=num; i++){

                // check if the condition holds: ans[i] OR (ans[i] + 1) == num
                if((i | (i+1)) == num){
                    // if found, push the value of ans[i] into the result array
                    res[id++] = i;
                    found = true;
                    // no need to check further, move to the next number
                    break;
                }
            }

            // if no valid ans[i] was found, push -1 to indicate it's not possible
            if(!found){
                res[id++] = -1;
            }
        }

        // return the constructed ans array
        return res;
    }

    public static void main(String[] args) {
        // List<Integer> nums = Arrays.asList(2, 3, 5, 7);

        List<Integer> nums = Arrays.asList(11, 13, 31);
        int[] res = minBitwiseArray(nums);
        System.out.println(Arrays.toString(res));
    }
}
