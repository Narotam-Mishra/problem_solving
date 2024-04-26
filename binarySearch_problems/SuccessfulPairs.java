
// Problem link - https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

package BinarySearch_problems;

import java.util.*;

public class SuccessfulPairs {
    
    static class Pair implements Comparable<Pair>{
        int strength;
        int index;

        public Pair(int strength, int index){
            this.strength = strength;
            this.index = index;
        }

        @Override
        public int compareTo(Pair other){
            return Integer.compare(this.strength, other.strength);
        }
    }

    // Utility method to reverse an array
    private static void reverseArray(int[] arr) {
        int left = 0;
        int right = arr.length - 1;
        while (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }

    public static int[] successfulPairs(int[] spells, int[] potions, long success) {
        int m = potions.length, n = spells.length;

        // create pairs array to store spell strength and index
        Pair[] pairs = new Pair[n];
        for(int i=0; i<n; i++){
            pairs[i] = new Pair(spells[i], i);
        }

        // sort array of pairs by strength
        Arrays.sort(pairs);

        // Sort potions array in descending order
        Arrays.sort(potions);
        reverseArray(potions);

        // array to store success pair count
        int[] successPairs = new int[n];

        // For each spell of spells, count successful pairs for each spell
        for(int i=0, j=0; i<n; i++){
            while (j < m && ((long) potions[j] * pairs[i].strength) >= success) {
                j++;
            }
            // update the count of successful pairs at the original spell index
            successPairs[pairs[i].index] = j;
        }

        // Return array with counts of successful pairs for each spell in original order
        return successPairs;
    }

    public static void main(String[] args) {
        int[] spells = { 5, 1, 3 };
        int[] potions = { 1, 2, 3, 4, 5 };
        int success = 7;

        int[] result = successfulPairs(spells, potions, success);
        System.out.println(Arrays.toString(result));
    }
}
