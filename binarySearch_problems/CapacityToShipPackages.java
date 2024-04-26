
// Problem link - https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

package BinarySearch_problems;

/**
 * CapacityToShipPackages
 */
public class CapacityToShipPackages {
    private static boolean canShipMidWeightWithinDdays(int[] arr, int mid, int days){
        int runningWeight = 0, dc = 0;
        for(int i=0; i<arr.length; i++){
            if(runningWeight + arr[i] > mid){
                dc++;
                runningWeight = 0;
            }
            runningWeight += arr[i];
        }
        dc++;  // increment day counter dc for last weight
        return dc <= days;
    }
    public static int shipWithinDays(int[] weights, int days) {
        int maxWeight = -1, totalWeight = 0;

        for(int w : weights){
            maxWeight = Math.max(maxWeight, w);
            totalWeight += w;
        }
        // since we may not load more weight than the maximum weight capacity of the ship.
        //hence search space will be from low = maxweight to high = totalWeight

        int low = maxWeight, high = totalWeight;
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(canShipMidWeightWithinDdays(weights, mid, days)){
                // we got the first probable answer, ans
                ans = mid;
                // since we need to find least weight capacity, 
                // hence we will discard right half of search space
                high = mid - 1;
            }else{
                // otherwise discard left half
                low = mid + 1;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] arr = {1,2,3,4,5,6,7,8,9,10};
        int days = 5;
        int ans = shipWithinDays(arr, days);
        System.out.println(ans);
    }
}