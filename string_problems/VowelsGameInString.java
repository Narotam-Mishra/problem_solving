
// Problem link - https://leetcode.com/problems/vowels-game-in-a-string/description/?envType=daily-question&envId=2025-09-12

package string_problems;

public class VowelsGameInString {
    public static boolean doesAliceWin(String s) {
        // step 1 - count vowels in the input string `s`
        int vowelsCount = 0;
        for(char ch : s.toCharArray()){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                vowelsCount++;
            }
        }

        // step 2 - if vowels count is not zero then `Alice` wins, so return true
        // otherwise return false
        return vowelsCount != 0 ? true : false;
    }

    public static void main(String[] args) {
        // String s = "leetcoder";

        String s = "bbcd";
        System.out.println(doesAliceWin(s));
    }
}
