
// Problem link : https://leetcode.com/problems/valid-palindrome-ii/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

package string_problems;

public class ValidPalindromeII {

    // helper function to check if a substring of string 's' is a palindrome
    private static boolean checkPalindromeInRange(String str, int left, int right){
        while(left < right){
            // mismatch found
            if(str.charAt(left) != str.charAt(right)) return false;
            left++;
            right--;
        }
        // No mismatches, it's a palindrome
        return true;
    }

    public static boolean validPalindrome(String s) {
        // using two pointers approach
        int l = 0, r = s.length() - 1;

        // move pointers towards each other
        while(l < r){
            if(s.charAt(l) != s.charAt(r)){
                // if mismatch found, try skipping either the left or right character
                return checkPalindromeInRange(s, l+1, r) || checkPalindromeInRange(s, l, r-1);
            }
            l++;
            r--;
        }
        // if no mismatches, or it's already a palindrome
        return true;
    }

    public static void main(String[] args) {
        // String str = "abca";

        // String str = "aba";

        String str = "abc";
        System.out.println(validPalindrome(str));
    }
}