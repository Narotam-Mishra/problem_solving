
// Problem link - http://leetcode.com/problems/find-valid-pair-of-adjacent-digits-in-string?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

public class FindValidPairOfAdjacentDigitInString {
    public static String findValidPair(String s) {
        // step 1 - create a frequency map using fixed size array to count the occurrences of each digit in the string
        int[] freq = new int[10];

        // step 2 - populate the frequency array map
        for(char ch : s.toCharArray()){
            freq[ch - '0']++;
        }

        // step 3 - traverse the string to check for the first valid pair
        for(int i=0; i<s.length() - 1; i++){
            int firstDigit = s.charAt(i) - '0';
            int secondDigit = s.charAt(i+1) - '0';

            // a valid pair requires the two digits to be different
            if(firstDigit != secondDigit){
                // check if the frequency of each digit matches its numeric value
                if(freq[firstDigit] == firstDigit && freq[secondDigit] == secondDigit){
                    return s.substring(i, i+2);
                }
            }
        }

        // step 4 - if no valid pair is found, return an empty string
        return "";
    }

    public static void main(String[] args) {
        // String s = "2523533";

        // String s = "221";

        String s = "22";
        System.out.println(findValidPair(s));
    }
}