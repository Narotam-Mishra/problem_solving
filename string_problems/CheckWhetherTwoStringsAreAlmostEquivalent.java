
// Problem link - https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/?envType=problem-list-v2&envId=string

package string_problems;

public class CheckWhetherTwoStringsAreAlmostEquivalent {
    public static boolean checkAlmostEquivalent(String word1, String word2) {
        // step 1 - using frequency array `frq`
        int[] frq = new int[26];

        // step 2 - count frequency of characters in word1
        for(char ch : word1.toCharArray()){
            frq[ch - 'a']++;
        }

        // step 3 - subtract frequency for characters in word2
        for(char ch : word2.toCharArray()){
            frq[ch - 'a']--;
        }

        // step 4 - check if absolute difference is more than 3
        for(int i=0; i<26; i++){
            if(Math.abs(frq[i]) > 3){
                return false;
            }
        }

        // step 5 - return true if all diffs are within 3
        return true;
    }

    public static void main(String[] args) {
        // String word1 = "aaaa", word2 = "bccb";

        // String word1 = "abcdeef", word2 = "abaaacc";

        String word1 = "cccddabba", word2 = "babababab";
        System.out.println(checkAlmostEquivalent(word1, word2));
    }
}