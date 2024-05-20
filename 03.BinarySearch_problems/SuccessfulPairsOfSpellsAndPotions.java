
// Problem link - https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/

package BinarySearch_problems;

import java.util.Arrays;

/**
 * SuccessfulPairsOfSpellsAndPotions
 */
public class SuccessfulPairsOfSpellsAndPotions {
    private static int findLowerBound(int[] arr, double x){
        int s = 0, e = arr.length - 1;
        int ans = arr.length;

        while(s <= e){
            int mid = (s + e)/2;
            if(x > arr[mid]){
                // discard left half of array
                s = mid + 1;
            }else{
                // found first proabable ans's element index
                ans = mid;
                e = mid - 1;
            }
        }
        return ans;
    }
    public static int[] successfulPairs(int[] spells, int[] potions, long success) {
        // sort potions array in ascending order
        Arrays.sort(potions);

        // array to store successful pair count
        int n = spells.length;
        int [] successPairs = new int[n];

        for(int i=0; i<n; i++){
            // minimum strength required for success
            double minStrength = Math.ceil((double) success / spells[i]);
            // Count successful pairs
            int countpairs = potions.length - findLowerBound(potions, minStrength);
            successPairs[i] = countpairs;
        }
        return successPairs;
    }

    public static void main(String[] args) {
        int[] spells = {5,1,3};
        int[] potions = {1,2,3,4,5};
        int success = 7;
        int[] ans = successfulPairs(spells, potions, success);
        System.out.println("Success Pairs Array:"+ Arrays.toString(ans));
    }
}