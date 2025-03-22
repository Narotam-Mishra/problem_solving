
// Problem link - https://leetcode.com/problems/valid-word/?envType=problem-list-v2&envId=string

package string_problems;

public class ValidWord {
    public static boolean isValid(String word){
        // check all conditions using if else
        if(word.length() < 3) return false;
        boolean hasVowel = false, hasConsonant = false;
        
        // iterate on each character of word
        for(int i=0; i<word.length(); i++){
            char ch = word.charAt(i);
            if((ch>='a'&& ch<='z') || (ch>='A' && ch<='Z')){
                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'){
                    hasVowel = true;
                }else{
                    hasConsonant = true;
                }
            }else if(ch>='0' && ch<='9'){
                continue;
            }else{
                return false;
            }
        }

        return hasVowel && hasConsonant;
    }

    public static boolean isValid1(String word) {
        // step 1 - check the length constraint
        if(word.length() < 3) return false;

        // step 2 - ensure only valid characters (letters and digits) are present
        if(!word.matches("^[a-zA-Z0-9]+$")) return false;

        // step 3 - define string of vowels
        String vowels = "aeiouAEIOU";
        boolean hasVowel = false, hasConsonant = false;

        // step 4 - iterate on each character of input `word`
        for(char ch : word.toCharArray()){
            if(vowels.indexOf(ch) != -1){
                // found atleast one vowel
                hasVowel = true;
            }else if(!Character.isDigit(ch)){
                // if it's not a number, it's a consonant
                hasConsonant = true;
            }

            // step 5 - if both conditions are met, no need to check further
            if(hasVowel && hasConsonant){
                return true;
            }
        }

        // step 6 - return false if any condition is not met
        return false;
    }

    public static void main(String[] args) {
        String word = "234Adas";

        // String word = "b3";

        // String word = "a3$e";
        System.out.println(isValid(word));
    }
}