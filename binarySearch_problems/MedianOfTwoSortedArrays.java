
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
    public static double findMedianSortedArrays1(int[] nums1, int[] nums2) {
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

    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length;
        int i = 0, j = 0;
        int len = m + n;
        int mid = len / 2;
        int preMid = mid - 1;
        int cnt = 0;
        int indNum1 = -1, indNum2 = -1;

        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                if (cnt == preMid)
                    indNum1 = nums1[i];
                if (cnt == mid)
                    indNum2 = nums1[i];
                cnt++;
                i++;
            } else {
                if (cnt == preMid)
                    indNum1 = nums2[j];
                if (cnt == mid)
                    indNum2 = nums2[j];
                cnt++;
                j++;
            }
        }

        // if any element left in nums1
        while (i < m) {
            if (cnt == preMid)
                indNum1 = nums1[i];
            if (cnt == mid)
                indNum2 = nums1[i];
            cnt++;
            i++;
        }

        // if any element left in nums2
        while (j < n) {
            if (cnt == preMid)
                indNum1 = nums2[j];
            if (cnt == mid)
                indNum2 = nums2[j];
            cnt++;
            j++;
        }

        // if size is odd
        if (len % 2 == 1) {
            return indNum2;
        }

        return (double) (indNum1 + indNum2) / 2.0;
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