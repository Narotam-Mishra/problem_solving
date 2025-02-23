
// Problem link - https://leetcode.com/problems/number-of-different-integers-in-a-string/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

public class NumberOfDifferentIntegersInString {
    public static int numDifferentIntegers(String word) {
        // step 1 - replace all non-digit characters with spaces
        StringBuilder changedWord = new StringBuilder();
        for(char ch : word.toCharArray()){
            if(Character.isDigit(ch)){
                changedWord.append(ch);
            }else{
                changedWord.append(" ");
            }
        }

        // step 2 - split the modified string into tokens based on spaces
        String[] tokens = changedWord.toString().split(" ");

        // step 3 - remove leading zeros and store unique integers in a HashSet
        Set<String> set = new HashSet<>();
        for(String token : tokens){
            // skip empty token
            if(token.isEmpty()) continue;

            // remove leading zeros
            String processedToken = token.replaceFirst("^0+(?!$)", "");
            if(processedToken.isEmpty()){
                // handle case where all digits are zeros
                processedToken = "0";
            }
            set.add(processedToken);
        }

        // step 4 - return the number of unique integers
        return set.size();
    }

    public static void main(String[] args) {
        // String word = "a123bc34d8ef34";

        // String word = "leet1234code234";

        String word = "a1b01c001";
        System.out.println(numDifferentIntegers(word));
    }
}