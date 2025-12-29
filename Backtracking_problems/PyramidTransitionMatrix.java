
// Problem link - https://leetcode.com/problems/pyramid-transition-matrix/description/?envType=daily-question&envId=2025-12-29

package Backtracking_problems;

import java.util.*;

public class PyramidTransitionMatrix {
    // memoization map
    private static Map<String, Boolean> memo = new HashMap<>();

    private static boolean solveRec(
        String curr,                          // current row
        Map<String, List<Character>> mp,      // mapping of bottom pair -> possible top blocks
        int idx,                              // current index in curr
        StringBuilder above                  // row being built above curr
    ) {
        String key = curr + "_" + idx + "_" + above.toString();

        // Base case: reached the top
        if (curr.length() == 1) {
            memo.put(key, true);
            return true;
        }

        // Memoization check
        if (memo.containsKey(key)) {
            return memo.get(key);
        }

        // Finished building current row, move to next level
        if (idx == curr.length() - 1) {
            boolean res = solveRec(above.toString(), mp, 0, new StringBuilder());
            memo.put(key, res);
            return res;
        }

        // Current bottom pair
        String pair = curr.substring(idx, idx + 2);

        // No valid top block
        if (!mp.containsKey(pair)) {
            memo.put(key, false);
            return false;
        }

        // Try all possible top blocks
        for (char ch : mp.get(pair)) {
            above.append(ch);          // choose

            if (solveRec(curr, mp, idx + 1, above)) {
                memo.put(key, true);
                return true;
            }

            above.deleteCharAt(above.length() - 1); // backtrack
        }

        memo.put(key, false);
        return false;
    }

    public static boolean pyramidTransition(String bottom, List<String> allowed) {
        Map<String, List<Character>> mp = new HashMap<>();

        // Build mapping
        for (String pattern : allowed) {
            String key = pattern.substring(0, 2);
            char top = pattern.charAt(2);

            mp.computeIfAbsent(key, k -> new ArrayList<>()).add(top);
        }

        return solveRec(bottom, mp, 0, new StringBuilder());
    }

    public static void main(String[] args) {
        // String bottom = "BCD";
        // String[] allowed = {"BCC","CDE","CEA","FFF"};

        String bottom = "AAAA";
        String[] allowed = {"AAB","AAC","BCD","BBE","DEF"};
        System.out.println(pyramidTransition(bottom, Arrays.asList(allowed)));
    }
}
