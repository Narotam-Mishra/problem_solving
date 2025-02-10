
// Problem link : https://leetcode.com/problems/minimum-common-value/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

public class MinimumCommonValue {
    public static int getCommon1(int[] nums1, int[] nums2) {
        // step 1 - intialize two pointers for both arrays `nums1` & `nums2`
        int i=0, j=0;

        // step 2 - iterate both arrays using two pointers
        while(i < nums1.length && j < nums2.length){
            // if both numbers are equal
            if(nums1[i] == nums2[j]){
                // then we found the smallest common integer
                return nums1[i];
            }else if(nums1[i] < nums2[j]){
                // move pointer in nums1 forward
                i++;
            }else{
                // move pointer in nums2 forward
                j++;
            }
        }

        // step 3 - otherwise return -1
        return -1;
    }

    public static int getCommon(int[] nums1, int[] nums2) {
        HashSet<Integer> numSet = new HashSet<>();
        
        // step 1 - store all elements of nums1 in a HashSet
        for (int num : nums1) {
            numSet.add(num);
        }
        
        // step 2 - check if any element in nums2 exists in set1
        for (int num : nums2) {
            if (numSet.contains(num)) {
                // return the first common number found
                return num; 
            }
        }
        
        // step 3 - no common element found, return -1
        return -1; 
    }

    public static void main(String[] args) {
        int[] nums1 = {1, 2, 3};
        int[] nums2 = {2, 4};

        // int[] nums1 = {1, 2, 3, 6};
        // int[] nums2 = {2, 3, 4, 5};
        System.out.println(getCommon(nums1, nums2));
    }
}