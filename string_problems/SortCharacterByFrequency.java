
// Problem link - https://leetcode.com/problems/sort-characters-by-frequency/?envType=problem-list-v2&envId=string

package string_problems;

import java.util.*;

public class SortCharacterByFrequency {
    public static String frequencySort(String s) {
        // step 1 - count frequency of each character using HashMap
        Map<Character, Integer> count = new HashMap<>();
        for(char ch : s.toCharArray()){
            count.put(ch, count.getOrDefault(ch, 0) + 1);
        }

        // step 2 - create list of characters and sort by its frequency
        List<Character> chars = new ArrayList<>(count.keySet());
        chars.sort((a, b) -> count.get(b) - count.get(a));

        // step 3 - build resultant string
        StringBuilder res = new StringBuilder();
        for(char ch : chars){
            int frq = count.get(ch);
            for(int i=0; i<frq; i++){
                res.append(ch);
            }
        }

        // step 4 - return resultant string `res`
        return res.toString();
    }

    public static void main(String[] args) {
        // String s = "tree";

        // String s = "cccaaa";

        String s = "Aabb";
        System.out.println(frequencySort(s));
    }
}