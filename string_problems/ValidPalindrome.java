
// Problem link : https://leetcode.com/problems/valid-palindrome/description/

package string_problems;

public class ValidPalindrome {
    private static String stringConversion(String str){
        return str.toLowerCase().replaceAll("[^a-z0-9]", "");
    }

    public static boolean isPalindrome(String s) {
        // remove all non-alphanumeric characters from string
        s = stringConversion(s);

        // now reverse the string
        int l = 0, r = s.length() - 1;
        while(l < r){
            if(s.charAt(l) != s.charAt(r)){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    public static void main(String[] args) {
        // String s = "A man, a plan, a canal: Panama";

        String s = "race a car";
        System.out.println(isPalindrome(s));
    }
}