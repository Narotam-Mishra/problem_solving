
// Problem link - https://leetcode.com/problems/maximize-the-number-of-partitions-after-operations/?envType=daily-question&envId=2025-10-17

package DynamicProgramming_problems;

import java.util.*;

public class MaximizeNumberOfPartitionsAfterOperations {
    // memoization map: stores computed results for (index, uniqueChars bitmask, canChange flag)
    static Map<Long, Integer> memo = new HashMap<>();
    
    static String str;
    static int K;

    private static int solveRec(long i, long uniqueChars, boolean canChange) {
        // create unique key combining: index (bits 27+), uniqueChars bitmask (bits 1-26), canChange flag (bit 0)
        long key = ((i << 27) | (uniqueChars << 1) | (canChange ? 1 : 0));

        // return cached result if already computed
        if (memo.containsKey(key)) {
            return memo.get(key);
        }

        // base case: reached end of string, no more partitions possible
        if (i >= str.length()) {
            return 0;
        }

        // get character index (0-25 for 'a'-'z')
        int charIndex = str.charAt((int)i) - 'a';
        
        // add current character to the bitmask (set corresponding bit)
        int newUniqueChars = (int)uniqueChars | (1 << charIndex);
        
        // count number of distinct characters using bitCount (counts set bits)
        int uniqueCharsCount = Integer.bitCount(newUniqueChars);

        int res;
        // if adding current character exceeds K distinct characters
        if (uniqueCharsCount > K) {
            // start a new partition: increment count and reset bitmask to only current character
            res = 1 + solveRec(i + 1, 1 << charIndex, canChange);
        } else {
            // continue current partition: keep the updated bitmask
            res = solveRec(i + 1, newUniqueChars, canChange);
        }

        // if we still have the option to change one character
        if (canChange) {
            // try changing current character to each of 26 possible letters
            for (int newCharId = 0; newCharId < 26; newCharId++) {
                // calculate new bitmask with the changed character
                int newCharSet = (int)uniqueChars | (1 << newCharId);
                int newUniqueCharCount = Integer.bitCount(newCharSet);

                // if changing causes partition split
                if (newUniqueCharCount > K) {
                    // start new partition with changed character, mark canChange as false
                    res = Math.max(res, 1 + solveRec(i + 1, 1 << newCharId, false));
                } else {
                    // continue partition with changed character, mark canChange as false
                    res = Math.max(res, solveRec(i + 1, newCharSet, false));
                }
            }
        }

        // cache and return the result
        memo.put(key, res);
        return res;
    }

    public static int maxPartitionsAfterOperations(String s, int k) {
        str = s;
        K = k;

        // start with empty bitmask (0), canChange = true
        // add 1 because we count partition boundaries, need to add final partition
        return solveRec(0, 0, true) + 1;
    }

    public static void main(String[] args) {
        String s = "accca";
        int k = 2;

        // String s = "aabaab";
        // int k = 3;

        // String s = "xxyz";
        // int k = 1;
        System.out.println(maxPartitionsAfterOperations(s, k));
    }
}