
// Problem link - https://leetcode.com/problems/remove-palindromic-subsequences/?envType=problem-list-v2&envId=string

package string_problems;

public class RemovePalindromicSubsequences {
    // utility method to check if string is palindrome or not
    private static boolean isPalindrome(String str){
        int l = 0, r = str.length() - 1;

        while(l < r){
            if(str.charAt(l) != str.charAt(r)){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    public static int removePalindromeSub(String s) {
        // step 1 - if input string `s` is palindrome then we can remove it in 1 step
        // otherwise , remove all a's in one step and all b's in another step
        return isPalindrome(s) ? 1 : 2;
    }

    public static void main(String[] args) {
        // String s = "ababa";

        // String s = "abb";

        String s = "baabb";
        System.out.println(removePalindromeSub(s));
    }
}