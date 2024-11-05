
// Problem link : https://leetcode.com/problems/to-lower-case/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

package string_problems;

public class ToLowerCase {
    public static String toLowerCase1(String s) {
        return s.toLowerCase();
    }

    public static String toLowerCase(String s) {
        // change string to character array
        char[] chars = s.toCharArray();

        // iterate over each character
        for(int i=0; i<chars.length; i++){
            // check if character is uppercase
            if(chars[i] >= 'A' && chars[i] <= 'Z'){
                // convert to lowercase by adding 32
                chars[i] = (char)(chars[i] + 32);
            }
        }

        // convert char array back to string
        return new String(chars);
    }

    public static void main(String[] args) {
        String str = "LOVELY";

        // String str = "Hello World";

        // String str = "here";
        System.out.println(toLowerCase(str));
    }
}