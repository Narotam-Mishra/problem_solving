
//Problem link - https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/

package BinarySearch_problems;

import java.util.Arrays;

public class MinimizeTheMaxDiffOfPairs {
    private static boolean canFormAtLeastPpairsWithAtMostMidDiff(int[] arr, int mid, int p){
        int i=0, count = 0;
        while(i < arr.length - 1){
            // check whether the diff is atmost mid
            if(arr[i+1] - arr[i] <= mid){
                count++;
                i += 2;
            }else{
                i++;
            }
        }
        return count >= p;
    }
    public static int minimizeMax(int[] nums, int p) {
        // sort the array so the it will be easy find p pairs
        Arrays.sort(nums);

        // for search space minimum value, low is 0 and maximum value, high is maximum - minimum value in nums array
        int low = 0, high = nums[nums.length - 1] - nums[0];
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(canFormAtLeastPpairsWithAtMostMidDiff(nums, mid, p)){
                // found first probable answer as mid hence ans = mid
                ans = mid;
                // since difference amongst all the pairs is minimized
                // so discard the right half of search space
                high = mid - 1;
            }else{
                // otherwise discard the left half of search space
                low = mid + 1;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] arr = {10,1,2,7,1,3};
        int p = 2;
        int ans = minimizeMax(arr, p);
        System.out.println(ans);
    }
}
