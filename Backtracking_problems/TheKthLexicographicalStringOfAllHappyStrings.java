
// Problem link - https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/?envType=daily-question&envId=2026-03-14

package Backtracking_problems;

import java.util.*;

public class TheKthLexicographicalStringOfAllHappyStrings {
    private static void solveRec(StringBuilder curr, List<String> res, int n){
        // base case
        if (curr.length() == n) {
            res.add(curr.toString());
            return;
        }

        // backtracking
        for (char ch = 'a'; ch <= 'c'; ch++) {

            // avoid same adjacent characters
            if (curr.length() > 0 && curr.charAt(curr.length() - 1) == ch)
                continue;

            // do
            curr.append(ch);

            // explore
            solveRec(curr, res, n);

            // undo
            curr.deleteCharAt(curr.length() - 1);
        }
    }

    public static String getHappyString(int n, int k) {
        StringBuilder curr = new StringBuilder();
        List<String> res = new ArrayList<>();

        solveRec(curr, res, n);

        if (k > res.size())
            return "";

        return res.get(k - 1);
    }

    public static void main(String[] args) {
        // int n = 1, k = 3;

        // int n = 3, k = 9;

        int n = 1, k = 4;
        System.out.println(getHappyString(n, k));
    }
}
