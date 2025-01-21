
// Problem link : https://leetcode.com/problems/kth-distinct-string-in-an-array/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

public class KthDistinctStringInArray {
    public static String kthDistinct(String[] arr, int k) {
        // step - 1 - count the frequency of each string using a object (map)
        Map<String, Integer> freqMap = new HashMap<>();
        for(String str : arr){
            freqMap.put(str, freqMap.getOrDefault(str, 0) + 1);
        }

        // step - 2 - return the kth distinct string (1-based index)
        for(String str : arr){
            if(freqMap.get(str) == 1){
                k--;
            }
            if(k == 0){
                return str;
            }
        }
        return "";
    }

    public static void main(String[] args) {
        // String[] arr = {"d","b","c","b","c","a"};
        // int k = 2;

        // String[] arr = {"aaa","aa","a"};
        // int k = 1;

        String[] arr = {"a","b","a"};
        int k = 3;
        System.out.println(kthDistinct(arr, k));
    }
}