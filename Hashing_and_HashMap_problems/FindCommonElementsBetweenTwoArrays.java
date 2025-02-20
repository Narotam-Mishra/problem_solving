
// Problem link - https://leetcode.com/problems/find-common-elements-between-two-arrays/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

public class FindCommonElementsBetweenTwoArrays {
    public static int[] findIntersectionValues1(int[] nums1, int[] nums2) {
        // step 1 - initialize counters for the answers
        int ans1 = 0, ans2 = 0;

        // step 2 - add nums1 & nums2 numbers in set1 & set2 respectively for best lookup
        Set<Integer> set1 = new HashSet<>();
        for(int num : nums1){
            set1.add(num);
        }

        Set<Integer> set2 = new HashSet<>();
        for(int num : nums2){
            set2.add(num);
        }

        // step 3 - count how many elements in nums1 exist in nums2 and vice versa
        for(int num : nums1){
            if(set2.contains(num)){
                ans1++;
            }
        }

        for(int num : nums2){
            if(set1.contains(num)){
                ans2++;
            }
        }

        // step 4 - return the results as an array
        return new int[]{ans1, ans2};
    }

    public static int[] findIntersectionValues(int[] nums1, int[] nums2) {
        // step 1 - initialize counters for the answers
        int ans1 = 0, ans2 = 0;

        // step 2 - add nums1 & nums2 numbers in arr1 & arr2 respectively for best lookup
        boolean[] arr1 = new boolean[101];
        for(int num : nums1){
            arr1[num] = true;
        }
        boolean[] arr2 = new boolean[101];
        for(int num : nums2){
            arr2[num] = true;
        }

        // step 3 - count how many elements in nums1 exist in arr2 and vice versa
        for(int num : nums1){
            if(arr2[num] == true){
                ans1++;
            }
        }

        for(int num : nums2){
            if(arr1[num] == true){
                ans2++;
            }
        }

        // step 4 - return the results as an array
        return new int[]{ans1, ans2};
    }

    public static void main(String[] args) {
        int[] nums1 = {2, 3, 2};
        int[] nums2 = {1, 2};

        // int[] nums1 = {4,3,2,3,1};
        // int[] nums2 = {2,2,5,2,3,6};

        // int[] nums1 = {3,4,2,3};
        // int[] nums2 = {1, 5};
        int[] res = findIntersectionValues(nums1, nums2);
        System.out.println(Arrays.toString(res));
    }
}