
// Problem link - https://leetcode.com/problems/create-target-array-in-the-given-order/description/?envType=problem-list-v2&envId=array

package Array_problems;

import java.util.*;

public class CreateTargetArrayInGivenOrder {
    public static int[] createTargetArray(int[] nums, int[] index) {
        int n = nums.length;

        // strore result in target array `target`
        List<Integer> list = new ArrayList<>();

        // step 1 - process each (value, index) pair from left to right
        for (int i = 0; i < n; i++) {
            // current value to insert
            int value = nums[i];

            // position where to insert
            int idx = index[i];

            // step 2 - insert value at specified index and shift existing elements to the
            // right
            list.add(idx, value);
        }

        // step 3 - return target list by converting into array
        int[] target = new int[n];
        for(int i=0; i<n; i++){
            target[i] = list.get(i);
        }
        return target;
    }

    public static void main(String[] args) {
        // int[] nums = {0,1,2,3,4}, index = {0,1,2,2,1};

        // int[] nums = {1,2,3,4,0}, index = {0,1,2,3,0};

        int[] nums = {1}, index = {0};
        int[] res = createTargetArray(nums, index);
        System.out.println(Arrays.toString(res));
    }
}
