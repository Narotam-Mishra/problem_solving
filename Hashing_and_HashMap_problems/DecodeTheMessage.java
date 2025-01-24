
// Problem link : https://leetcode.com/problems/decode-the-message/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

public class DecodeTheMessage {
    public static String decodeMessage(String key, String message) {
        // step 1 - build the substitution map
        Map<Character, Character> substitutionMap = new HashMap<>();
        // start with char 'a'
        char alphabet = 'a';

        // iterate through the key to extract unique letters
        for(char ch : key.toCharArray()){
            // skip space and already mapped characters
            if(ch != ' ' && !substitutionMap.containsKey(ch)){
                substitutionMap.put(ch, alphabet);
                alphabet++;

                // stop if all 26 letters have been mapped
                if(alphabet > 'z') break;
            }
        }

        // step 2 - decode the message
        StringBuilder decodedMessage = new StringBuilder();
        for(char ch : message.toCharArray()){
            if(substitutionMap.containsKey(ch)){
                // substitute using map
                decodedMessage.append(substitutionMap.get(ch));
            }else{
                // space remain unchnaged
                decodedMessage.append(ch);
            }
        }

        // step 3 - return decoded message
        return decodedMessage.toString();
    }

    public static void main(String[] args) {
        // String key = "eljuxhpwnyrdgtqkviszcfmabo", message = "zwx hnfx lqantp mnoeius ycgk vcnjrdb";
        
        String key = "the quick brown fox jumps over the lazy dog", message = "vkbs bs t suepuv";
        System.out.println(decodeMessage(key, message));
    }
}