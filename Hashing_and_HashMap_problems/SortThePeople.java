
// Problem link : https://leetcode.com/problems/sort-the-people/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.Arrays;

public class SortThePeople {
    public static String[] sortPeople(String[] names, int[] heights) {
        // step 1 - create an array of indices
        Integer[] indices = new Integer[heights.length];
        for(int i=0; i<heights.length; i++){
            indices[i] = i;
        }

        // step 2 - sort indices based on heights in descending order
        Arrays.sort(indices, (a, b) -> Integer.compare(heights[b], heights[a]));

        // step 3 - create the result array using sorted indices
        String[] res = new String[names.length];
        for(int i=0; i<indices.length; i++){
            res[i] = names[indices[i]];
        }

        // step 4 - return resutant array `res`
        return res;
    }

    public static void main(String[] args) {
        String[] names = {"Mary","John","Emma"};
        int[] heights = {180, 165, 170};
        String[] res = sortPeople(names, heights);
        System.out.println(Arrays.toString(res));
    }
}