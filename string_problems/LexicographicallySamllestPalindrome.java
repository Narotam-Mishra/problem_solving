
// Problem link - https://leetcode.com/problems/lexicographically-smallest-palindrome/?envType=problem-list-v2&envId=string

package string_problems;

public class LexicographicallySamllestPalindrome {
    public static String makeSmallestPalindrome(String s) {
        // step 1 - make string into char array
        char[] strArr = s.toCharArray();

        // step 2 - use two pointers approach 
        int i=0, j=strArr.length-1;

        // step 3 - process characters from both ends
        while(i < j){
            if(strArr[i] != strArr[j]){
                // step 4 - replace the character that gives the lexicographically smaller result
                char smallerChar = (char)Math.min(strArr[i], strArr[j]);
                strArr[i] = strArr[j] = smallerChar;
            }
            i++;
            j--;
        }

        // step 5 - return char array back into string
        return new String(strArr);
    }

    public static void main(String[] args) {
        // String s = "egcfe";

        // String s = "abcd";

        String s = "seven";
        System.out.println(makeSmallestPalindrome(s));
    }
}