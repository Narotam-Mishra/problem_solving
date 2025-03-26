
// Problem link - https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/?envType=problem-list-v2&envId=string

package string_problems;

public class CountPrefixAndSuffixPairsI {
    public static int countPrefixSuffixPairs(String[] words) {
        // step 1 - initialize the count
        int count = 0;

        // step 2 - iterate on each word of words
        for(int i=0; i<words.length; i++){
            // step 3 - iterate on each pair of words
            for(int j=i+1; j<words.length; j++){
                // step 4 - check if prefix and suffix exist
                if(words[j].startsWith(words[i]) && words[j].endsWith(words[i])){
                    // increment the counter
                    count++;
                }
            }
        }

        // step 5 - return count
        return count;
    }

    public static void main(String[] args) {
        // String[] words = {"a","aba","ababa","aa"};

        // String[] words = {"pa","papa","ma","mama"};

        String[] words = {"abab","ab"};
        System.out.println(countPrefixSuffixPairs(words));
    }
}