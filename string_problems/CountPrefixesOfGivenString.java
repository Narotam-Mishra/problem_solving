
// Problem link : https://leetcode.com/problems/count-prefixes-of-a-given-string/description/

package string_problems;

public class CountPrefixesOfGivenString {
    public static int countPrefixes(String[] words, String s) {
        // initialize the prefix count `prefixCount` to 0
        int prefixCount = 0;

        // iterate through each word in the 'words' array
        for(String word : words){
            // check if the current word is a prefix of 's'
            if(s.startsWith(word)){
                prefixCount++;
            }
        }

        // return the total count of prefixes
        return prefixCount;
    }

    public static void main(String[] args) {
        // String[] words = {"a","b","c","ab","bc","abc"};
        // String s = "abc";

        String[] words = {"a","a"};
        String s = "aa";
        System.out.println(countPrefixes(words, s));
    }
}