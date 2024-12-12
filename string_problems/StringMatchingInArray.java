
// Problem link : https://leetcode.com/problems/string-matching-in-an-array/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

package string_problems;

import java.util.*;

public class StringMatchingInArray {
    public static List<String> stringMatching(String[] words) {
        // step 1: sort words by length (shorter strings come first)
        Arrays.sort(words, Comparator.comparingInt(String::length));

        // store result in res
        Set<String> res = new HashSet<>();

        // step 2: check each string against longer strings
        for(int i=0; i<words.length; i++){
            for(int j=i+1; j<words.length; j++){
                // check if words[i] is a substring of words[j]
                if(words[j].contains(words[i])){
                    // add to the result set 'res'
                    res.add(words[i]);
                    break;
                }
            }
        }

        // step 3: convert result set to a list and return
        return new ArrayList<>(res);
    }

    public static void main(String[] args) {
        // String[] words = {"mass","as","hero","superhero"};

        // String[] words = {"leetcode","et","code"};

        String[] words = {"blue","green","bu"};
        System.out.println(stringMatching(words));
    }
}