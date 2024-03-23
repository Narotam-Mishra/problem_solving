
// Problem link - https://leetcode.com/problems/split-array-largest-sum/description/

package binarySearch_problems;

public class SplitArrayLargestSum {
    private static boolean isBestWayToSplitArrayWithMidSubArray(int[] arr, int mid, int k){
        int sc = 0, runningSum = 0;
        for(int i=0; i<arr.length; i++){
            // if sub array running sum is greater than mid
            // increment the subArray counter, sc
            if(arr[i] + runningSum > mid){
                sc++;
                runningSum = 0;
            }
            runningSum += arr[i];
        }
        // increment sub array counter, sc for last running subArray sum, runningSum
        sc++;
        return sc <= k;
    }
    public static int splitArray(int[] nums, int k) {
        int maxNum = -1, totalSum = 0;

        for(int num : nums){
            maxNum = Math.max(maxNum, num);
            totalSum += num;
        }

        // since we have to find the minimized largest sum of the split (in sub array)
        // hence the search space will be from low = maxNum (maximum number in array) to high = totalSum (total sum of array)
        int low = maxNum, high = totalSum;
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(isBestWayToSplitArrayWithMidSubArray(nums, mid, k)){
                // found the first probale answer as mid
                ans = mid;
                // since we have to find the minimized largest sum of the split
                // hence we discard right half of search space
                high = mid - 1;
            }else{
                // discard left half of search space
                low = mid + 1;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] arr = {7,2,5,10,8};
        int k = 2;
        int ans = splitArray(arr, k);
        System.out.println(ans);
    }
}
