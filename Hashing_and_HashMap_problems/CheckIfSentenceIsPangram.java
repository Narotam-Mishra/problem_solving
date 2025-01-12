
// Problem link : https://leetcode.com/problems/check-if-the-sentence-is-pangram/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

public class CheckIfSentenceIsPangram {
    public static boolean checkIfPangram1(String sentence) {
        // step 1 - create a frequency array and fill frequency of each input string characters
        int[] mapArr = new int[26];
        for(char ch : sentence.toCharArray()){
            mapArr[ch - 'a']++;
        }

        // step 2 - iterate over frequecny array
        for(int i=0; i<26; i++){
            // check frequency of each input string characters
            if(mapArr[i] < 1){
                // if it is less than 1 return false
                return false;
            }
        }
        // otherwise return true;
        return true;
    }

    public static boolean checkIfPangram(String sentence) {
        // step 1 - iterate through each letter of the alphabet
        for(int i='a'; i<='z'; i++){
            // step 2 - check if the current letter is present in the sentence
            if(sentence.indexOf(i) < 0){
                // step 3 - if any letter is not found, return false
                return false;
            }
        }
        // step 4 - if all letters are found, return true
        return true;
    }

    public static void main(String[] args) {
        // String sentence = "thequickbrownfoxjumpsoverthelazydog";

        String sentence = "leetcode";
        System.out.println(checkIfPangram(sentence));
    }
}