
// Problem link : https://leetcode.com/problems/two-out-of-three/description/?envType=problem-list-v2&envId=bit-manipulation&status=TO_DO&difficulty=EASY

package BitMasking_Problems;

import java.util.*;

public class TwoOutOfThree {
    private static void updateFrequency(Map<Integer, Integer> freqMap, int[] arr){
        // using a set to ensure unique elements in the array
        Set<Integer> unique = new HashSet<>();
        for(int num : arr){
            unique.add(num);
        }

        // update frequency map
        for(int num : unique){
            freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
        }
    }
    public static List<Integer> twoOutOfThree(int[] nums1, int[] nums2, int[] nums3) {
        // define a frequency map
        Map<Integer, Integer> freqMap = new HashMap<>();

        // function to update the frequency map based on unique elements from an array
        updateFrequency(freqMap, nums1);
        updateFrequency(freqMap, nums2);
        updateFrequency(freqMap, nums3);

        // collect numbers that appear in at least two arrays
        List<Integer> res = new ArrayList<>();
        for(Map.Entry<Integer, Integer> entry : freqMap.entrySet()){
            if(entry.getValue() >= 2){
                res.add(entry.getKey());
            }
        }
        // return resultant 'res' array
        return res;
    }

    public static void main(String[] args) {
        int[] nums1 = {1,1,3,2};
        int[] nums2 = {2, 3};
        int[] nums3 = {3};
        System.out.println(twoOutOfThree(nums1, nums2, nums3));
    }
}