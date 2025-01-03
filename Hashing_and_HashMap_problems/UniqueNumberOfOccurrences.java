
// Problem link : https://leetcode.com/problems/unique-number-of-occurrences/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

public class UniqueNumberOfOccurrences {
    public static boolean uniqueOccurrences(int[] arr) {
        // step 1 - create a HashMap to count the occurrences of each element
        Map<Integer, Integer> map = new HashMap<>();
        for(int num : arr){
            map.put(num, map.getOrDefault(num, 0) + 1);
        }

        // step 2 - use a HashSet to store the unique frequencies
        Set<Integer> set = new HashSet<>(map.values());

        // step 3 - compare the size of the Set and the Map
        return map.size() == set.size();
    }

    public static void main(String[] args) {
        // int[] arr = {1,2,2,1,1,3};

        // int[] arr = {1,2};

        int[] arr = {-3,0,1,-3,1,1,1,-3,10,0};
        System.out.println(uniqueOccurrences(arr));
    }
}