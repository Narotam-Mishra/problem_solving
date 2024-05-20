
// Problem link - https://leetcode.com/problems/merge-sorted-array/description/

// Approach - 1 (without using extra array)
// TC - O(m+n)

package Array_problems;

/**
 * MergeSortedArrays
 */
public class MergeSortedArrays {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i = m-1, j = n-1, k = m+n-1;

        while(i>=0 && j>=0){
            // compare each number of nums1[] with nums2[] from reverse
            if(nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                i--;
                k--;
            }else{
                // nums2[j] > nums1[i]
                nums1[k] = nums2[j];
                j--;
                k--;
            }
        }

        // if nums2[] is exhausted, copy all numbers from nums1
        while(i>=0){
            nums1[k] = nums1[i];
            i--;
            k--;
        }

        // if nums1[] is exhausted, copy all numbers from nums2
        while(j>=0){
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    } 
}