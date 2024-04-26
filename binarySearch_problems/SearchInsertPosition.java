
// Problem link - https://leetcode.com/problems/search-insert-position/description/

package BinarySearch_problems;

/**
 * SearchInsertPosition
 */
public class SearchInsertPosition {
    public static int findLowerBound(int[] arr, int x){
        int s = 0, e = arr.length - 1;
        int ans = arr.length;

        while (s <= e) {
            int mid = s + (e-s)/2;
            if(x > arr[mid]){
                // discard left half of array
                s = mid + 1;
            }else{
                // find the probable ans
                ans = mid;
                e = mid - 1;
            }
        }
        return ans;
    }
    public int searchInsert(int[] nums, int target) {
        int lb = findLowerBound(nums, target);
        return lb;
    }
}