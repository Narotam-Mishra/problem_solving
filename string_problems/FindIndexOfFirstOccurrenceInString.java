
// Problem link : https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

package string_problems;

public class FindIndexOfFirstOccurrenceInString {
    public static int strStr(String haystack, String needle) {
        return haystack.indexOf(needle);
    }

    public static void main(String[] args) {
        String haystack = "sadbutsad", needle = "sad";
        System.out.println(strStr(haystack, needle));
    }
}