
// Problem link : https://leetcode.com/problems/reverse-vowels-of-a-string/description/?envType=study-plan-v2&envId=leetcode-75

package Array_problems;

public class ReverseVowelsOfString {

    public static String reverseVowels(String s) {
        String vowels = "aeiouAEIOU";
        int left = 0, right = s.length() - 1;
        
        // convert string to char array
        char[] chars = s.toCharArray();

        while(left < right){
            // move left pointer until it finds a vowel
            while (left < right && vowels.indexOf(chars[left]) == -1) {
                left++;
            }

            // move right pointer until it finds a vowel
            while(left < right && vowels.indexOf(chars[right]) == -1){
                right--;
            }

            // swap vowels
            char temp = chars[left];
            chars[left] = chars[right];
            chars[right] = temp;

            left++;
            right--;
        }
        return new String(chars);
    }

    public static void main(String[] args) {
        // String str = "hello";

        String str = "leetcode";
        System.out.println(reverseVowels(str));
    }
}