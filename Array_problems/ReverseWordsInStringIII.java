
// Problem link : https://leetcode.com/problems/reverse-words-in-a-string-iii/description/

package Array_problems;

public class ReverseWordsInStringIII {

    private static String reverseUtil(String str){
        StringBuilder sb = new StringBuilder(str);
        return sb.reverse().toString();
    }

    public static String reverseWords(String s) {
        // split the sentence into words
        String[] words = s.split(" ");
        StringBuilder res = new StringBuilder();

        // iterate on each word
        for(int i=0; i<words.length; i++){
            // reverse each word and add to result
            res.append(reverseUtil(words[i]));

            // add space between words except after
            if(i < words.length - 1){
                res.append(" ");
            }
        }
        return res.toString();
    }

    public static void main(String[] args) {
        String s = "Let's take LeetCode contest";
        System.out.println(reverseWords(s));
    }
}