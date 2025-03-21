
// Problem link - https://leetcode.com/problems/find-first-palindromic-string-in-the-array/?envType=problem-list-v2&envId=string

package string_problems;

public class FindFirstPalindromicStringInArray {
    // utility method to check if string is palindromic or not
    private static boolean isPalindromicString(String str){
        int s = 0, e = str.length() - 1;
        while(s < e){
            if(str.charAt(s) != str.charAt(e)){
                return false;
            }
            s++;
            e--;
        }
        return true; 
    }

    public static String firstPalindrome(String[] words) {
        // step 1 - iterate on each word 
        for(String word : words){
            // step 2 - check if it is palindromic string or not
            if(isPalindromicString(word)){
                // step 3 - return word immediately if it is palindromic
                return word;
            }
        }
        // step 4 - otherwise return empty string
        return "";
    }

    public static void main(String[] args) {
        // String[] words = {"abc","car","ada","racecar","cool"};

        // String[] words = {"notapalindrome","racecar"};

        String[] words = {"def","ghi"};
        System.out.println(firstPalindrome(words));
    }
}