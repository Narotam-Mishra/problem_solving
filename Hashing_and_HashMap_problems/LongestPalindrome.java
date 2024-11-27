
// Problem link : https://leetcode.com/problems/longest-palindrome/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

package Hashing_and_HashMap_problems;

import java.util.HashMap;

public class LongestPalindrome {
    public static int longestPalindrome(String s) {
        // step 1: count the frequency of each character,
        // for counting using hash map
        HashMap<Character, Integer> charCount = new HashMap<>();
        for(char ch : s.toCharArray()){
            charCount.put(ch, charCount.getOrDefault(ch, 0) + 1);
        }

        int longestPalindromeLength = 0;
        boolean hasOdd = false;

        // step 2: calculate contributions to the palindrome
        for(int count : charCount.values()){
            if(count % 2 == 0){
                // if even, all characters can contribute to the palindrome
                longestPalindromeLength += count;
            }else{
                // if odd, use the largest even part and flag that an odd exists
                longestPalindromeLength += count - 1;
                hasOdd = true;
            }
        }

        // step 3: add 1 if there's an odd character to be the center
        if(hasOdd){
            longestPalindromeLength += 1;
        }

        // return longest palindrome length 'longestPalindromeLength'
        return longestPalindromeLength;
    }

    public static void main(String[] args) {
        // String str = "abccccdd";

        String str = "a";
        System.out.println(longestPalindrome(str)); 
    }
}