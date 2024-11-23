
// Problem link :- https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/description/?envType=problem-list-v2&envId=number-theory&status=TO_DO&difficulty=EASY

package NumberTheory_Problems;

import java.util.*;

public class XKindDeckOfCards {

    // helper function to calculate the greatest common divisor (GCD) using Euclid's algorithm
    private static int findGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    public static boolean hasGroupsSizeX(int[] deck) {
        // step 1: create a frequency map to store frequency of each number
        Map<Integer, Integer> frqMap = new HashMap<>();

        for(int cardNum : deck){
            frqMap.put(cardNum, frqMap.getOrDefault(cardNum, 0) + 1);
        }

        // step 2: extract frequency values
        int[] counts = new int[frqMap.size()];
        int index = 0;
        for(int count : frqMap.values()){
            counts[index++] = count;
        }

        // step 3: compute GCD for all frequency counts
        int overallGCD = counts[0];
        for(int i=1; i<counts.length; i++){
            overallGCD = findGCD(overallGCD, counts[i]);

            // early exit: if at any point GCD becomes 1, no valid grouping is possible
            if(overallGCD == 1) return false;
        }

        // step 4: return true if GCD >= 2
        return overallGCD >= 2;
    }

    public static void main(String[] args) {
        // int[] deck = {1,2,3,4,4,3,2,1};

        int[] deck = {1,1,1,2,2,2,3,3};
        System.out.println(hasGroupsSizeX(deck));
    }
}