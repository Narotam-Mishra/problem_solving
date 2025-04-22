package string_problems;

public class ReplaceAllDigitsWithCharacters {
    public static String replaceDigits(String s) {
        // step 1 - convert input string `s` to char array
        char[] chars = s.toCharArray();

        // step 2 - iterate through each character and perform shift operation
        for(int i=1; i<chars.length; i+=2){
            // get character
            char ch = chars[i-1];

            // get digit
            int digit = chars[i] - '0';

            // step 3 - perform shift operation 
            chars[i] = (char)(ch + digit);
        }

        // step 4 - return char array `arr` by convert back to string
        return new String(chars);
    }

    public static void main(String[] args) {
        // String s = "a1c1e1";

        String s = "a1b2c3d4e";
        System.out.println(replaceDigits(s));
    }
}