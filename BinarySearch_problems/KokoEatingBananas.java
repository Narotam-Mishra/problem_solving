
// Problem link - https://leetcode.com/problems/koko-eating-bananas/description/

package BinarySearch_problems;

/**
 * KokoEatingBananas
 */
public class KokoEatingBananas {

    private static boolean canKokoEatAllBananasInMidSpeed(int[] piles, int mid, int h) {
        // time taken to eat a pile of banans = ceil value of(piles[i]/mid)
        // where piles[i] is number of bananas in ith pile and 'mid' is speed
        int totalHrsToEat = 0;
        for (int i = 0; i < piles.length; i++) {
            // total time to finish ith pile
            totalHrsToEat += Math.ceil((double) piles[i] / mid);
        }
        // check if total bananas finished within h hours
        return totalHrsToEat <= h;
    }

    public static int minEatingSpeed(int[] piles, int h) {
        // define the search space to determine minimum speed k
        // minimum 1 and maximum max number of piles to determine search space
        int maxBananas = Integer.MIN_VALUE;
        for (int num : piles) {
            maxBananas = Math.max(maxBananas, num);
        }
        // let us assume ans i.e minimum speed is 1
        int s = 1, e = maxBananas, ans = 1;
        
        while (s <= e) {
            int mid = (s + e) / 2;
            // check if Koko can eat all bananas at mid speed within 'h' hrs
            if (canKokoEatAllBananasInMidSpeed(piles, mid, h)) {
                // get one probable ans as mid
                ans = mid;
                // since we need to find minimum speed 'k' hence we discard right half of array
                e = mid - 1;
            } else {
                // otherwise discard left half of array
                s = mid + 1;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] arr = {30,11,23,4,20};
        int h = 5;
        System.out.println(minEatingSpeed(arr, h));
    }
}