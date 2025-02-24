
// Problem link - https://leetcode.com/problems/existence-of-a-substring-in-a-string-and-its-reverse/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

public class ExistenceOfSubstringInStringAndReverse {
    public static boolean isSubstringPresent1(String s) {
        // edge case:
        if(s.length() == 2){
            return s.charAt(0) == s.charAt(1);
        }

        // step 1 - store all substrings of length 2 from s in set
        Set<String> set = new HashSet<>();
        for(int i=0; i<s.length()-1; i++){
            set.add("" + s.charAt(i) + s.charAt(i+1));
        }

        // step 2 - check if any substring from reversed string exists in the set
        for(int i=s.length()-1; i>0; i--){
            if(set.contains("" + s.charAt(i) + s.charAt(i-1))){
                // return true if substring found
                return true;
            }
        }

        // step 3 - if no substring found, return false
        return false;
    }

    public static boolean isSubstringPresent(String s){
        // step 1 - reverse the string
        String reversed = new StringBuilder(s).reverse().toString();

        // step 2 - check if substring of length 2 exists in reversed string
        for(int i=0; i<s.length()-1; i++){
            String sub = s.substring(i, i+2);
            if(reversed.contains(sub)){
                // return true if substring found
                return true;
            }
        }

        // step 3 - return false if no substring found
        return false;
    }

    public static void main(String[] args) {
        // String s = "leetcode";

        // String s = "abcba";

        String s = "abcd";
        System.out.println(isSubstringPresent(s));
    }
}