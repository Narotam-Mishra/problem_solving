
// Problem link : https://leetcode.com/problems/number-of-equivalent-domino-pairs/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.HashMap;
import java.util.Map;

public class NumberOfEquivalentDominoPairs {
    public static int numEquivDominoPairs(int[][] dominoes) {
        // step 1 - map to store frequency of normalized dominoes
        Map<String, Integer> map = new HashMap<>();
        for(int[] domino : dominoes){
            int a = domino[0];
            int b = domino[1];

            // normalize the domino
            String key = Math.min(a,b) + "," + Math.max(a,b);

            // set the key pair count in map
            map.put(key, map.getOrDefault(key, 0) + 1);
        }

        // step 2 - calculate the number of pairs
        int pairs = 0;
        for(int count : map.values()){
            if(count >= 2){
                pairs += (count * (count - 1)) / 2;
            }
        }

        // step 3 - return number of valid pairs
        return pairs;
    }

    public static void main(String[] args) {
        // int[][] dominoes = {{1,2},{2,1},{3,4},{5,6}};

        int[][] dominoes = {{1,2},{1,2},{1,1},{1,2},{2,2}};
        System.out.println(numEquivDominoPairs(dominoes));
    }
}