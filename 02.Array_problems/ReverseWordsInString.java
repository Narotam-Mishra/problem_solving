
// Problem link - https://leetcode.com/problems/reverse-words-in-a-string/

package Array_problems;

public class ReverseWordsInString {
    public String reverseWords(String s) {
        // Split the string by any number of spaces and filter out empty strings
        String[] words = s.trim().split("\\s+");

        int st = 0, e = words.length - 1;
        while(st < e){
            String temp = words[st];
            words[st] = words[e];
            words[e] = temp;
            st++;
            e--;
        }
        return String.join(" ", words);
    }
}
