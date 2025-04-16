
// Problem link - https://leetcode.com/problems/find-maximum-number-of-string-pairs/description/?envType=problem-list-v2&envId=string

package string_problems;

import java.util.*;

public class FindMaximumNumberOfStringPairs {
    public static int maximumNumberOfStringPairs(String[] words) {
        // step 1 - use a set to keep track of words we've seen but not yet paired
        Set<String> seen = new HashSet<>();
        int count = 0;

        // step 2 - iterate through each word of words
        for(String word : words){
            // step 3 - reverse the current word
            String revStr = new StringBuilder(word).reverse().toString();
            
            // step 4 - check if the revered word has been seen before
            if(seen.contains(revStr)){
                count++;
            }else{
                // step 5 - if no match found, add to set
                seen.add(word);
            }
        }

        // step 6 - return maximum number of reversed string pairs
        return count;
    }

    public static void main(String[] args) {
        // String[] words = {"cd","ac","dc","ca","zz"};

        // String[] words = {"ab","ba","cc"};

        String[] words = {"aa","ab"};
        System.out.println(maximumNumberOfStringPairs(words));
    }
}