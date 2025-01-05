
// Problem link : https://leetcode.com/problems/rank-transform-of-an-array/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

public class RankTransformOfAnArray {
    public static int[] arrayRankTransform(int[] arr) {
        // step 1 - Pair elements with their original indices
        int[][] pair = new int[arr.length][2];
        for(int i=0; i< arr.length; i++){
            pair[i][0] = arr[i];
            pair[i][1] = i;
        }

        // step 2 - sort the array by its value
        Arrays.sort(pair, (a, b) -> Integer.compare(a[0], b[0]));

        // step 3 - assign ranks
        int[] ranks = new int[arr.length];
        int rank = 1;
        for (int i = 0; i < pair.length; i++) {
            // if the current value is not equal to the previous value,
            if (i > 0 && pair[i][0] != pair[i - 1][0]) {
                // incremnt the rank
                rank++;
            }
            // otherwise assign the same rank
            ranks[pair[i][1]] = rank;
        }

        // step 4 - return ranks
        return ranks;
    }

    public static void main(String[] args) {
        // int[] arr = {40,10,20,30};

        // int[] arr = {100, 100, 100};

        int[] arr = {37,12,28,9,100,56,80,5,12};
        int[] res = arrayRankTransform(arr);
        System.out.println(Arrays.toString(res));
    }
}