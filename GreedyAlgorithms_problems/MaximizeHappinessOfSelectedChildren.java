
// problem link - https://leetcode.com/problems/maximize-happiness-of-selected-children/?envType=daily-question&envId=2025-12-25

package GreedyAlgorithms_problems;

import java.util.*;

public class MaximizeHappinessOfSelectedChildren {
    public static long maximumHappinessSum(int[] happiness, int k) {
        // store final result in `res`
        long res = 0;

        // step 1 - store happiness in max-Heap
        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b) -> b - a);
        for(int h : happiness){
            pq.add(h);
        }

        // step 2 - keep track of number of child picked in `count` till now
        int count = 0;
        for(int i=0; i<k; i++){
            // get top happines value from `pq`
            int hapValue = pq.poll();

            // step 3 - calculate maximum possible happiness value
            res += Math.max(0, hapValue - count);

            // increment count as we have picked one child
            count++;
        }

        // step 4 - return the maximum sum of the happiness from `res`
        return res;
    }

    public static void main(String[] args) {
        // int[] happiness = {1,2,3};
        // int k = 2;

        // int[] happiness = {1,1,1,1};
        // int k = 2;

        int[] happiness = {2,3,4,5};
        int k = 1;
        System.out.println(maximumHappinessSum(happiness, k));
    }
}
