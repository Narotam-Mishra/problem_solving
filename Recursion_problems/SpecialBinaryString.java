
// Problem link - https://leetcode.com/problems/special-binary-string/description/

package Recursion_problems;

import java.util.*;

public class SpecialBinaryString {
    // recursive function to make special string lexicographically largest
    private static String solveRec(String s) {

        // list to store top-level special substrings
        List<String> specialStrs = new ArrayList<>();

        int sum = 0;      // balance counter (+1 for '1', -1 for '0')
        int start = 0;    // starting index of current special substring

        // step 1 - traverse string to split into maximum top-level special substrings
        for (int i = 0; i < s.length(); i++) {

            // update balance
            sum += (s.charAt(i) == '1') ? 1 : -1;

            // step 2 - if balance becomes 0, we found one complete special substring
            if (sum == 0) {

                // extract inner substring (excluding outer 1 and 0)
                String inner = s.substring(start + 1, i);

                // step 3 - recursively process inner substring
                String processed = "1" + solveRec(inner) + "0";

                specialStrs.add(processed);

                // move start to next position
                start = i + 1;
            }
        }

        // step 4 - sort in descending lexicographical order
        Collections.sort(specialStrs, Collections.reverseOrder());

        // step 5 - concatenate all sorted substrings
        StringBuilder result = new StringBuilder();
        for (String str : specialStrs) {
            result.append(str);
        }
        return result.toString();
    }

    public static String makeLargestSpecial(String s) {
        return solveRec(s);
    }

    public static void main(String[] args) {
        // String s = "11011000";

        String s = "10";
        System.out.println(makeLargestSpecial(s));
    }
}
