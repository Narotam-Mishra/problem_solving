
// Problem link : https://leetcode.com/problems/maximum-number-of-pairs-in-array/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.Arrays;

public class MaximumNumberOfPairsInArray {
    public static int[] numberOfPairs(int[] nums) {
        // step 1 - create frequency array map to count frquency of each array elements
        int[] freqMapArr = new int[101];
        for(int num : nums){
            freqMapArr[num]++;
        }

        // step 2 - calculate number of pairs and number of left over elements from frequency array map
        int numOfPairs = 0, numOfleftOvers = 0;
        for(int count : freqMapArr){
            // count how many pairs can be formed
            numOfPairs += count / 2;

            // count remaining unpaired numbers
            numOfleftOvers += count % 2;
        }

        // step 3 - return required result
        return new int[]{numOfPairs, numOfleftOvers};
    }

    public static void main(String[] args) {
        // int[] nums = {1,3,2,1,3,2,2};

        // int[] nums = {1,1};

        int[] nums = {0};
        int[] res = numberOfPairs(nums);
        System.out.println(Arrays.toString(res));
    }
}