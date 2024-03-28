
// Problem link - https://leetcode.com/problems/median-of-two-sorted-arrays/

// Approach - Brute Force Method

package binarySearch_problems;

/**
 * MedianOfTwoSortedArrays
 */
public class MedianOfTwoSortedArrays {
    private static int[] mergeSortedArrays(int[] arr1, int[] arr2, int m, int n) {
        int i = 0, j = 0, k = 0;

        int[] res = new int[m + n];
        while (i < m && j < n) {
            if (arr1[i] < arr2[j]) {
                res[k] = arr1[i];
                k++;
                i++;
            } else {
                res[k] = arr2[j];
                k++;
                j++;
            }
        }

        // if any element left in arr1
        while (i < m) {
            res[k] = arr1[i];
            k++;
            i++;
        }

        // if any element left in arr2
        while (j < n) {
            res[k] = arr2[j];
            k++;
            j++;
        }

        return res;
    }
    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;

        int[] mergedArr = mergeSortedArrays(nums1, nums2, m, n);
        int size = mergedArr.length;
        int mid = size/2;

        // if array length is even
        if(size%2 == 0){
            double f = (double)mergedArr[mid];
            double s = (double)mergedArr[mid-1];
            return (f+s)/2;
        }else{
            return (double)mergedArr[mid];
        }
    }

    public static void main(String[] args) {

        int[] arr1 = {1,3};
        int[] arr2 = {2};

        // int[] arr1 = {1,2};
        // int[] arr2 = {3,4};
        double ans = findMedianSortedArrays(arr1, arr2);
        System.out.println(ans);
    }
}