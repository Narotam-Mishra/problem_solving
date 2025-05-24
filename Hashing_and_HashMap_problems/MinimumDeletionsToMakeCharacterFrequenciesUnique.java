
// Problem link - https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/description/

package Hashing_and_HashMap_problems;

import java.util.*;

public class MinimumDeletionsToMakeCharacterFrequenciesUnique {
    public static int minDeletions(String s) {
        // step 1 - store frequency of each character
        int[] frqMap = new int[26];
        for(char ch : s.toCharArray()){
            frqMap[ch - 'a']++;
        }

        // step 2 - use set to store used frequencies to ensure uniqueness
        Set<Integer> usedFrequencies = new HashSet<>();
        int deletionCount = 0;

        // step 3 - iterate on each frquency values
        for(int frq : frqMap){
            while(frq > 0 && usedFrequencies.contains(frq)){
                // simulate deleting one occurrence
                frq--;

                // count minimum deletion required
                deletionCount++;
            }

            // step 5 - if `frq > 0`, add it to the set of used frquencies
            if(frq > 0){
                usedFrequencies.add(frq);
            }
        }

        // step 6 - return minimum deletion needed to make good string
        return deletionCount;
    }

    public static void main(String[] args) {
        // String s = "aab";

        // String s = "aaabbbcc";

        String s = "ceabaacb";
        System.out.println(minDeletions(s));
    }
}