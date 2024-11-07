
// Problem link : https://leetcode.com/problems/detect-capital/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

package string_problems;

public class DetectCapital {
    public static boolean detectCapitalUse(String word) {
        // check for 1st condition : if all letters are uppercase
        if(word.equals(word.toUpperCase())) return true;

        // check for 2nd condition : if all letters are lowercase
        if(word.equals(word.toLowerCase())) return true;

        // check for 3rd condition : if only the first letter is uppercase and the rest are lowercase
        if(Character.isUpperCase(word.charAt(0)) && word.substring(1).equals(word.substring(1).toLowerCase())){
            return true;
        }
        // if none of three conditions are true then return false
        return false;
    }

    public static void main(String[] args) {
        // String str = "USA";

        // String str = "leetcode";

        String str = "FlaG";
        System.out.println(detectCapitalUse(str));
    }
}