
// Problem link : https://leetcode.com/problems/percentage-of-letter-in-string/description/?envType=problem-list-v2&envId=string

package string_problems;

public class PercentageOfLetterInString {
    public static int percentageLetter(String s, char letter) {
        // step 1: initialize a counter for the occurrences of the letter
        int len = s.length(), letterCount = 0;

        // step 2: iterate over each character in the string
        for(char ch : s.toCharArray()){
            if(ch == letter){
                letterCount++;
            }
        }

        // step 3: calculate the percentage of the letter in the string
        int percentage = (letterCount * 100) / len;

        // step 4: return the percentage (no need to round down as integer division does it)
        return percentage;
    }

    public static void main(String[] args) {
        // String s = "foobar"; 
        // char letter = 'o';

        String s = "jjjj";
        char letter = 'k';
        System.out.println(percentageLetter(s, letter));
    }
}
