
// Problem link - https://leetcode.com/problems/palindrome-partitioning/?envType=problem-list-v2&envId=string

package string_problems;

import java.util.*;

public class PalindromePartitioning {
    // utlity method to checking palindromic string
    private static boolean isPalindromeString(String str){
        int l = 0, r = str.length()-1;

        while(l < r){
            if(str.charAt(l) != str.charAt(r)){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    // use recursive function to explore all possible partitions
    private static void backtrack(String s, int start, List<String> path, List<List<String>> res){
        // base case: if we have reached the end of string
        if(start == s.length()){
            res.add(new ArrayList<>(path));
            return;
        }

        // recursive case: explore all substrings from start to end
        for(int end = start+1; end <= s.length(); end++){
            String substr = s.substring(start, end);

            // check for pallindrome string
            if(isPalindromeString(substr)){
                path.add(substr);
                backtrack(s, end, path, res);
                path.remove(path.size() - 1);
            }
        }
    }

    public static List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<>();
        backtrack(s, 0, new ArrayList<>(), res);
        return res;
    }

    public static void main(String[] args) {
        // String s = "aab";

        String s = "a";
        List<List<String>> res = partition(s);
        System.out.println(res);
    }
}