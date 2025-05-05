
// Problem link - https://leetcode.com/problems/maximum-repeating-substring/?envType=problem-list-v2&envId=string

package string_problems;

public class MaximumRepeatingSubstring {
    public static int maxRepeating(String sequence, String word) {
        // step 1 - maximum number of times word can repeat within sequence
        int k = 1;

        // step 2 - repeat word k-times and check if it is substring of `sequence`
        while(sequence.contains(word.repeat(k))){
            // increment k
            k++;
        }

        // step 3 - the loop will break when substring is not found, so return k - 1
        return k - 1;
    }

    public static void main(String[] args) {
        // String sequence = "ababc", word = "ab";

        // String sequence = "ababc", word = "ba";

        String sequence = "ababc", word = "ac";
        System.out.println(maxRepeating(sequence, word));
    }
}