
// Problem link - https://leetcode.com/problems/words-within-two-edits-of-dictionary/?envType=daily-question&envId=2026-04-22

package string_problems;

import java.util.*;

public class WordsWithinTwoEditsOfDictionary {
    public List<String> twoEditWords(String[] queries, String[] dictionary) {
        // store final result in `res`
        List<String> res = new ArrayList<>();

        // step 1 - iterate on each query along with word of dictionary
        for (String query : queries) {
            for (String s : dictionary) {
                // keep track of difference
                int diff = 0;

                // step 2 - check each character of query with dictionary word
                for (int i = 0; i < query.length(); i++) {
                    // check for difference in character
                    if (s.charAt(i) != query.charAt(i)) {
                        diff++;
                    }

                    // atmost 2 differences are allowed
                    if (diff > 2) {
                        break;
                    }
                }

                // step 3 - store this query if its character has more than 2
                // differences
                if (diff <= 2) {
                    res.add(query);
                    break;
                }
            }
        }

        // step 4 - return final result, `res`
        return res;
    }

    public static void main(String[] args) {
        String[] queries = {"word","note","ants","wood"};
        String[] dictionary = {"wood","joke","moat"};
        WordsWithinTwoEditsOfDictionary obj = new WordsWithinTwoEditsOfDictionary();
        List<String> res = obj.twoEditWords(queries, dictionary);
        System.out.println(res);
    }
}
