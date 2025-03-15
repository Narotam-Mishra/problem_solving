
// Problem link - https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/?envType=problem-list-v2&envId=string

package string_problems;

public class DecryptStringFromAlphabetToIntegerMapping {
    public static String freqAlphabets(String s) {
        // step 1 - start form last character of `s`
        int i = s.length() - 1;
        StringBuilder res = new StringBuilder();

        // step 2 - iterate `s` from reverse
        while(i >= 0){
            // step 3 - decode two digits number (10# to 26#)
            if(s.charAt(i) == '#'){
                int num = Integer.parseInt(s.substring(i-2, i));
                // convert to letter
                res.append((char) (96 + num)); 
                i -= 3;
            }else{
                // step 4 - decode single-digit number (1 to 9)
                int num = s.charAt(i) - '0';
                res.append((char)(96 + num));
                i--;
            }
        }

        // step 5 - reverse the `res` to get correct order and return it
        return res.reverse().toString();
    }

    public static void main(String[] args) {
        // String s = "10#11#12";

        String s = "1326#";
        System.out.println(freqAlphabets(s));
    }
}