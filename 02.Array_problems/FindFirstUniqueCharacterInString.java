
// Problem link - https://leetcode.com/problems/first-unique-character-in-a-string/description/

package Array_problems;

import java.util.HashMap;

public class FindFirstUniqueCharacterInString {
    public static int firstUniqChar(String s) {
        HashMap<Character, Integer> strMap = new HashMap<>();
        // Iterate over the string to build the frequency map
        for(int i=0; i<s.length(); i++){
            char c = s.charAt(i);
            strMap.put(c, strMap.getOrDefault(c,0) + 1);
        }

        // Check the character which has frequency 1 and return its index
        for(int i=0; i<s.length(); i++){
            char c = s.charAt(i);
            if(strMap.get(c) == 1){
                return i;
            }
        }

        // If there is no unique character, return -1
        return -1;
    }

    public static void main(String[] args) {
        String str = "leetcode";
        System.out.println(firstUniqChar(str));
    }
}
