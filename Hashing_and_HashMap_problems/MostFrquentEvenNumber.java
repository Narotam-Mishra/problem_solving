
// Problem link - https://leetcode.com/problems/most-frequent-even-element/description/

package Hashing_and_HashMap_problems;

import java.util.*;

public class MostFrquentEvenNumber {
    public static int mostFrequentEven(int[] nums) {
        // step 1 - find frequency of each even number in `map`
        Map<Integer, Integer> map = new HashMap<>();
        for (int num : nums) {
            if (num % 2 == 0) {
                map.put(num, map.getOrDefault(num, 0) + 1);
            }
        }

        // step 2 - find most frquent event element by iterating on frquency map
        int maxFreq = -1;
        int result = -1;
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            int key = entry.getKey();
            int freq = entry.getValue();
            if (freq > maxFreq || (freq == maxFreq && key < result)) {
                maxFreq = freq;
                result = key;
            }
        }

        // step 3 - return the ans
        return result;
    }

    public static void main(String[] args) {
        // int[] nums = {0,1,2,2,4,4,1};

        // int[] nums = {4,4,4,9,2,4};

        int[] nums = {29,47,21,41,13,37,25,7};
        System.out.println(mostFrequentEven(nums));
    }
}