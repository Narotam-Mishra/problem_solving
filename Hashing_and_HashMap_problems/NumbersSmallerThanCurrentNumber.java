
// Problem link : https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

public class NumbersSmallerThanCurrentNumber {
    public static int[] smallerNumbersThanCurrent(int[] nums) {
        // step 1 - create an array of pairs (value, index)
        int[][] pairs = new int[nums.length][2];
        for(int i=0; i<nums.length; i++){
            pairs[i][0] = nums[i];
            pairs[i][1] = i;
        }

        // step 2 - sort the array by value
        Arrays.sort(pairs, (a,b) -> a[0] - b[0]);

        // step 3 - create a hash map to store the count of smaller numbers
        Map<Integer, Integer> map = new HashMap<>();

        // step 4 - iterate through the sorted array and assign counts based on the index
        for(int i=0; i<pairs.length; i++){
            // only assign if the number hasn't been assigned yet (to handle duplicates)
            if(!map.containsKey(pairs[i][0])){
                map.put(pairs[i][0], i);
            }
        }

        // step 5 : build the result array `res` and return `res`
        int[] res = new int[nums.length];
        for(int i=0; i<nums.length; i++){
            res[i] = map.get(nums[i]);
        }
        return res;
    }

    public static void main(String[] args) {
        int[] nums = {8,1,2,2,3};

        // int[] nums = {6,5,4,8};

        // int[] nums = {7,7,7,7};
        int[] res = smallerNumbersThanCurrent(nums);
        System.out.println(Arrays.toString(res));
    }
}