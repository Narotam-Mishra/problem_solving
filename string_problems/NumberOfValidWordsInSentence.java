
// Problem link - https://leetcode.com/problems/number-of-valid-words-in-a-sentence/?envType=problem-list-v2&envId=string

package string_problems;

import java.util.regex.Pattern;

public class NumberOfValidWordsInSentence {
    public static int countValidWords(String sentence) {
        // edge case:
        if(sentence == null || sentence.isEmpty()){
            return 0;
        }

        // step 1 - regular expression to match a valid word:
        Pattern validWordPattern = Pattern.compile("^[a-z]+(-[a-z]+)?[\\.!,]?$");

        // step 2 - regular expression to match a token that is exactly one punctuation mark.
        Pattern punctuationPattern = Pattern.compile("^[\\.!,]$");

        // step 3 - split the sentence into token by one or more spaces
        String[] tokens = sentence.trim().split("\\s+");
        int validWordCount = 0;

        // step 4 - check each token against regular expressions
        for(String token : tokens){
            if(validWordPattern.matcher(token).matches() || punctuationPattern.matcher(token).matches()){
                validWordCount++;
            }
        }

        // step 5 - return valid word count
        return validWordCount;
    }

    public static void main(String[] args) {
        // String sentence = "cat and  dog";

        // String sentence = "!this  1-s b8d!";

        String sentence = "alice and  bob are playing stone-game10";
        System.out.println(countValidWords(sentence));
    }
}