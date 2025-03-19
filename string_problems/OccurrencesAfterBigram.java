
// Problem link - https://leetcode.com/problems/occurrences-after-bigram/?envType=problem-list-v2&envId=string

package string_problems;

import java.util.*;

public class OccurrencesAfterBigram {
    public static String[] findOcurrences(String text, String first, String second) {
        // step 1 - split the text into words
        String[] words = text.split(" ");
        List<String> res = new ArrayList<>();

        // step 2 - iterate on each word
        for(int i=0; i<words.length-2; i++){
            // step 3 - check if current and next word match `first` and `second`
            if(words[i].equals(first) && words[i+1].equals(second)){
                // step 4 - add the third word to result
                res.add(words[i+2]);
            }
        }

        // step 5 - return the array of found words in String[]
        return res.toArray(new String[0]);
    }

    public static void main(String[] args) {
        // String text = "alice is a good girl she is a good student", first = "a", second = "good";

        String text = "we will we will rock you", first = "we", second = "will";
        String[] res = findOcurrences(text, first, second);
        System.out.println(Arrays.toString(res));
    }
}