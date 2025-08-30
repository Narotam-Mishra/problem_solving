
// Problem link - https://leetcode.com/problems/merge-similar-items/

package Array_problems;

import java.util.*;

public class MergeSimilarItems {
    // helper method to process array items
    private static void processItems(int[][] items, Map<Integer, Integer> valueWeightMap){
        for(int[] item : items){
            int value = item[0];
            int weight = item[1];

            // if value exist, add to existing weight,
            // otherwise add new entry
            valueWeightMap.put(value, valueWeightMap.getOrDefault(value,0) + weight);
        }
    }

    public static List<List<Integer>> mergeSimilarItems(int[][] items1, int[][] items2) {
        // step 1 - using TreeMap as it automatically maintains sorted order by value
        Map<Integer, Integer> valueWeightMap = new TreeMap<>();

        // step 2 - process array items
        processItems(items1, valueWeightMap);
        processItems(items2, valueWeightMap);

        // step 3 - convert Treemap to List<List<Integer>>
        List<List<Integer>> res = new ArrayList<>();
        for(Map.Entry<Integer, Integer> entry : valueWeightMap.entrySet()){
            List<Integer> item = Arrays.asList(entry.getKey(), entry.getValue());
            res.add(item);
        }

        // step 4 - return final resultant list `res`
        return res;
    }

    public static void main(String[] args) {
        // int[][] items1 = {{1,1},{4,5},{3,8}}, items2 = {{3,1},{1,5}};

        // int[][] items1 = {{1,1},{3,2},{2,3}}, items2 = {{2,1},{3,2},{1,3}};

        int[][] items1 = {{1,3},{2,2}}, items2 = {{7,1},{2,2},{1,4}};
        List<List<Integer>> res = mergeSimilarItems(items1, items2);
        System.out.println(res);
    }
}
