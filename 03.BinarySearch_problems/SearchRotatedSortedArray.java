
// Problem link - https://leetcode.com/problems/search-in-rotated-sorted-array/description/

package BinarySearch_problems;

/**
 * SearchRotatedSortedArray
 */
public class SearchRotatedSortedArray {
    public static int search(int[] nums, int target) {
        int s = 0, e = nums.length - 1;

        while(s <= e){
            int mid = (s + e)/2;
            if(nums[mid] == target) return mid;

            // identify sorted half of array and perform BS on sorted half
            // left half is sorted so discard right half and perform BS on left half
            if(nums[s] <= nums[mid]){
                if(nums[s] <= target && target <= nums[mid]){
                    // check if target is within start s and mid
                    e = mid - 1;
                }else{
                    s = mid + 1;
                }
            // right half is sorted so discard left half and perform BS on right half
            }else{
                if(nums[mid] <= target && target <= nums[e]){
                    // check if target is within mid and end e
                    s = mid + 1;
                }else{
                    e = mid - 1;
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] arr = {4,5,6,7,0,1,2};
        int target = 3;
        int ans = search(arr, target);
        System.out.println(ans);
    }
}