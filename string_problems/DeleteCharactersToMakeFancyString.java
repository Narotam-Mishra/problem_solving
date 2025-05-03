
// Problem link - https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/?envType=problem-list-v2&envId=string

package string_problems;

public class DeleteCharactersToMakeFancyString {
    public static String makeFancyString(String s) {
        // step 1 - store resultant string in `res` array
        StringBuilder res = new StringBuilder();

        // step 2 - iterate on input string `s`
        for(int i=0; i<s.length(); i++){
            // calculate of length `len` of result `res` string
            int len = res.length();

            // step 3 - check if last two characters in `res` are same as current character
            if(len >= 2 && res.charAt(len-1) == s.charAt(i) && res.charAt(len-2) == s.charAt(i)){
                // skip this character to avoid three consecutive characters
                continue;
            }

            // step 4 - otherwise add character to `res` array
            res.append(s.charAt(i));
        }

        // step 5 - return `res` by converting it into string
        return res.toString();
    }

    public static void main(String[] args) {
        // String s = "leeetcode";

        // String s = "aaabaaaa";

        String s = "aab";
        System.out.println(makeFancyString(s));
    }
}