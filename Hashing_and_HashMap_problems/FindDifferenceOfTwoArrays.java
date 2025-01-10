
// Problem link : https://leetcode.com/problems/find-the-difference-of-two-arrays/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

public class FindDifferenceOfTwoArrays {
    public static List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        // step 1 - create sets from the input arrays
        Set<Integer> set1 = new HashSet<>();
        Set<Integer> set2 = new HashSet<>();

        for(int num : nums1) {
            set1.add(num);
        }

        for(int num : nums2) {
            set2.add(num);
        }

        // step 2 - find elements unique to nums1
        List<Integer> uniqueNums1 = new ArrayList<>();
        for(int num : set1){
            if(!set2.contains(num)){
                uniqueNums1.add(num);
            }
        }

        // step 3 - find elements unique to nums2
        List<Integer> uniqueNums2 = new ArrayList<>();
        for(int num : set2){
            if(!set1.contains(num)){
                uniqueNums2.add(num);
            }
        }

        // step 4 - return the result as a list of two lists
        List<List<Integer>> res = new ArrayList<>();
        res.add(uniqueNums1);
        res.add(uniqueNums2);
        return res;
    }

    public static void main(String[] args) {
        int[] nums1 = {1, 2, 3};
        int[] nums2 = {2, 4, 6};
        List<List<Integer>> res = findDifference(nums1, nums2);
        System.out.println(res);
    }
}
