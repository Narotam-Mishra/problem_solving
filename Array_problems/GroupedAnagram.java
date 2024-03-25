
// Problem link - https://leetcode.com/problems/group-anagrams/description/

package Array_problems;

import java.util.*;


/**
 * GroupedAnagram
 */
public class GroupedAnagram {
    public static List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> groupedAnagrams = new HashMap<>();

        // iterate on each word of array of string
        for(String word : strs){
            // Sort the characters of the word to use as a key in the hash map
            char[] charArr = word.toCharArray();
            // to sort string, we need to convert it into char[] array first
            Arrays.sort(charArr);
            String sortedWord = new String(charArr);

            // If the sorted word is already a key, add the word to its corresponding array
            if(groupedAnagrams.containsKey(sortedWord)){
                groupedAnagrams.get(sortedWord).add(word);
            }else{
                // If the key doesn't exist, create a new array with the word
                List<String> anagramList = new ArrayList<String>();
                anagramList.add(word);
                groupedAnagrams.put(sortedWord, anagramList);
            }
        }

        for(Map.Entry<String, List<String>> entry : groupedAnagrams.entrySet()){
            System.out.println("Key: "+entry.getKey() + ", Value: "+entry.getValue());
        }

        // Convert the values of the map to a list of lists (grouped anagrams)
        return new ArrayList<>(groupedAnagrams.values());
    }

    public static void main(String[] args) {
        String[] strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
        List<List<String>> ans = groupAnagrams(strs);
        System.out.println(ans);
    }
}