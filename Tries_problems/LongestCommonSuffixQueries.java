
// Problem link - https://leetcode.com/problems/longest-common-suffix-queries/description/?envType=daily-question&envId=2026-05-28

package Tries_problems;

import java.util.*;

public class LongestCommonSuffixQueries {
    static class TrieNode {
        int idx;
        TrieNode[] children;

        TrieNode(int id) {
            idx = id;
            children = new TrieNode[26];
        }
    }

    private void insertInTrie(TrieNode root, int i, String[] wordsContainer) {
        String word = wordsContainer[i];
        int n = word.length();

        // Insert characters in reverse order to build a trie of suffixes.
        for (int j = n - 1; j >= 0; j--) {
            char ch = word.charAt(j);
            int chIdx = ch - 'a';

            if (root.children[chIdx] == null) {
                root.children[chIdx] = new TrieNode(i);
            }

            root = root.children[chIdx];

            if (wordsContainer[root.idx].length() > n) {
                root.idx = i;
            }
        }
    }

    private int searchInTrie(TrieNode root, String word) {
        int resIdx = root.idx;
        int n = word.length();

        for (int i = n - 1; i >= 0; i--) {
            int chIdx = word.charAt(i) - 'a';

            root = root.children[chIdx];
            if (root == null) {
                return resIdx;
            }

            resIdx = root.idx;
        }

        return resIdx;
    }

    public int[] stringIndices(String[] wordsContainer, String[] wordsQuery) {
        int m = wordsContainer.length;
        int n = wordsQuery.length;

        int[] res = new int[n];

        TrieNode root = new TrieNode(0);

        for (int i = 0; i < m; i++) {
            int idx = root.idx;

            if (wordsContainer[idx].length() > wordsContainer[i].length()) {
                root.idx = i;
            }

            insertInTrie(root, i, wordsContainer);
        }

        for (int i = 0; i < n; i++) {
            res[i] = searchInTrie(root, wordsQuery[i]);
        }

        return res;
    }

    public static void main(String[] args) {
        String[] wordsContainer = {"abcd", "bcd", "xbcd"};
        String[] wordsQuery = {"cd","bcd","xyz"};
        LongestCommonSuffixQueries obj = new LongestCommonSuffixQueries();
        int[] res = obj.stringIndices(wordsContainer, wordsQuery);
        System.out.println(Arrays.toString(res));
    }
}
