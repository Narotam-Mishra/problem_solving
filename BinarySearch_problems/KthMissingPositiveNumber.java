
// Problem link - https://leetcode.com/problems/kth-missing-positive-number/?envType=problem-list-v2&envId=binary-search

package BinarySearch_problems;

public class KthMissingPositiveNumber {
    public static int findKthPositive(int[] arr, int k) {
        // define the search space
        int s = 0, e = arr.length - 1;

        // step 1 - use binary search logic
        while (s <= e) {
            // calculate mid
            int mid = (s + e) / 2;

            // calculate the number of missing number counts
            int missingCounts = arr[mid] - (mid + 1);

            // if the missing numbers are less than k, move to the right
            if (missingCounts < k) {
                s = mid + 1;
            }
            // if the missing numbers are greater than or equal to k, move to the left
            else {
                e = mid - 1;
            }
        }

        // return kth missing number
        return k + e + 1;
    }

    public static void main(String[] args) {
        // int[] arr = {2,3,4,7,11};
        // int k = 5;

        int[] arr = {1, 2, 3, 4};
        int k = 2;
        System.out.println(findKthPositive(arr, k));
    }
}
