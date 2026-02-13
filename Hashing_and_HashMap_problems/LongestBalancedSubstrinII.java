
// Problem link - https://leetcode.com/problems/longest-balanced-substring-ii/?envType=daily-question&envId=2026-02-13

package Hashing_and_HashMap_problems;

import java.util.*;

public class LongestBalancedSubstrinII {
    static class Pair {
        int d1, d2;

        Pair(int d1, int d2) {
            this.d1 = d1;
            this.d2 = d2;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof Pair)) return false;
            Pair p = (Pair) o;
            return d1 == p.d1 && d2 == p.d2;
        }

        @Override
        public int hashCode() {
            return 31 * d1 + d2;
        }
    }

    private static int solve(char[] c, char x, char y) {
        int n = c.length;
        int max_len = 0;

        int[] first = new int[2 * n + 1];
        Arrays.fill(first, -2);

        int clear_idx = -1;
        int diff = n;

        first[diff] = -1;

        for (int i = 0; i < n; i++) {

            if (c[i] != x && c[i] != y) {

                clear_idx = i;
                diff = n;
                first[diff] = clear_idx;

            } else {

                if (c[i] == x) diff++;
                else diff--;

                if (first[diff] < clear_idx) {
                    first[diff] = i;
                } else {
                    max_len = Math.max(max_len, i - first[diff]);
                }
            }
        }

        return max_len;
    }

    public static int longestBalanced(String s) {
        char[] c = s.toCharArray();
        int n = c.length;

        int res = 0;

        //Case-1
        int cur = 1;

        for (int i = 1; i < n; i++) {
            if (c[i] == c[i - 1]) {
                cur++;
            } else {
                res = Math.max(res, cur);
                cur = 1;
            }
        }
        res = Math.max(res, cur);

        //Case-2
        res = Math.max(res, solve(c, 'a', 'b'));
        res = Math.max(res, solve(c, 'a', 'c'));
        res = Math.max(res, solve(c, 'b', 'c'));

        
        //Case-3
        int ca = 0, cb = 0, cc = 0;

        Map<Pair, Integer> mp = new HashMap<>();

        for (int i = 0; i < n; i++) {

            if (c[i] == 'a') ca++;
            else if (c[i] == 'b') cb++;
            else cc++;

            if(ca == cb && ca == cc)
                res = Math.max(res, ca+cb+cc);

            Pair key = new Pair(ca - cb, ca - cc);

            Integer prev = mp.get(key);
            if (prev != null) {
                res = Math.max(res, i - prev);
            } else {
                mp.put(key, i);
            }
        }

        return res;
    }

    public static void main(String[] args) {
        String s = "abbac";

        // String s = "aabcc";

        // String s = "aba";
        System.out.println(longestBalanced(s));
    }
}
