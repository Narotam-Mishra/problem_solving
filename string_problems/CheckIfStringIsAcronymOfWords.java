
// Problem link - https://leetcode.com/problems/check-if-a-string-is-an-acronym-of-words/?envType=problem-list-v2&envId=string

package string_problems;

import java.util.List;

public class CheckIfStringIsAcronymOfWords {
    public static boolean isAcronym(List<String> words, String s) {
        // edge case:
        if(s.length() != words.size()) return false;

        // step 1 - check first characters
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i) != words.get(i).charAt(0)){
                return false;
            }
        }

        // step 2 - return true if above condition is satified
        return true;
    }

    public static void main(String[] args) {
        // List<String> words = List.of("alice", "bob", "charlie");
        // String s = "abc";

        // List<String> words = List.of("an", "apple");
        // String s = "a";

        List<String> words = List.of("never","gonna","give","up","on","you");
        String s = "ngguoy";
        System.out.println(isAcronym(words, s));
    }
}