
// Problem link - https://leetcode.com/problems/check-if-word-equals-summation-of-two-words/?envType=problem-list-v2&envId=string

package string_problems;

public class CheckIfWordEqualsSummationOfTwoWords {
    // utility function to convert string to corresponding numeric value
    private static int getNumericValue(String s){
        StringBuilder numStr = new StringBuilder();

        for(char ch : s.toCharArray()){
            int digit = ch - 'a';
            numStr.append(digit);
        }
        return Integer.parseInt(numStr.toString());
    }

    public static boolean isSumEqual(String firstWord, String secondWord, String targetWord) {
        // step 1 - change input strings to corresponding numeric values
        int val1 = getNumericValue(firstWord);
        int val2 = getNumericValue(secondWord);
        int targetVal = getNumericValue(targetWord);

        // step 2 - check sum of numeric values are equal to corresponding numeric value of `targetWord`
        return (val1+val2) == targetVal;
    }

    public static void main(String[] args) {
        // String firstWord = "acb", secondWord = "cba", targetWord = "cdb";

        // String firstWord = "aaa", secondWord = "a", targetWord = "aab";

        String firstWord = "aaa", secondWord = "a", targetWord = "aaaa";
        System.out.println(isSumEqual(firstWord, secondWord, targetWord));
    }
}