
// Problem link - https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

package BinarySearch_problems;

/**
 * FirstAndLastPosition
 */

public class FirstAndLastPosition {

    public static int findLowerBound(int[] arr, int x){
        int s = 0, e = arr.length - 1;
        int ans = arr.length;

        while (s <= e) {
            int mid = s + (e - s)/2;
            if(arr[mid] < x){
                // discard left half
                s = mid + 1;
            }else{
                // got first probable ans
                ans = mid;
                e = mid - 1;
            }
        }
        return ans;
    }

    public static int findUpperBound(int[] arr, int x){
        int s = 0, e = arr.length - 1;
        int ans = arr.length;

        while (s <= e) {
            int mid = s + (e - s)/2;
            if(arr[mid] <= x){
                // discard left half
                s = mid + 1;
            }else{
                // got first probable ans
                ans = mid;
                e = mid - 1;
            }
        }
        return ans;
    }

    public int[] searchRange(int[] nums, int target) {
        int lb = findLowerBound(nums, target);
        int[] res = new int[2];

        if(lb == nums.length || nums[lb] != target){
            res[0] = -1;
            res[1] = -1;
        }else{
            int ub = findUpperBound(nums, target);
            res[0] = lb;
            res[1] = ub - 1;
        }
        return res;
    }
}