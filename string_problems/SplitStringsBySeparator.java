
// Problem link - https://leetcode.com/problems/split-strings-by-separator/description/?envType=problem-list-v2&envId=string

package string_problems;

import java.util.*;
import java.util.regex.Pattern;

public class SplitStringsBySeparator {
    public static List<String> splitWordsBySeparator(List<String> words, char separator) {
        // step 1 - store final result into `res`
        List<String> res = new ArrayList<>();

        // step 2 - iterate on each word of words
        for(String word : words){
            // step 3 - split the word by given separator
            String[] wordParts = word.split(Pattern.quote(String.valueOf(separator)));

            // step 4 - remove empty words
            for(String part : wordParts){
                if(!part.isEmpty()){
                    res.add(part);
                }
            }
        }

        // step 5 - return result list `res`
        return res;
    }

    public static void main(String[] args) {
        // List<String> words = Arrays.asList("one.two.three", "four.five", "six");
        // char separator = '.';

        // List<String> words = Arrays.asList("$easy$","$problem$");
        // char separator = '$';

        List<String> words = Arrays.asList("|||");
        char separator = '|';
        List<String> res = splitWordsBySeparator(words, separator);
        System.out.println(res);
    }
}