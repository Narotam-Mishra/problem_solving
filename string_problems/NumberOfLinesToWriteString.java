
// Problem link - https://leetcode.com/problems/number-of-lines-to-write-string/description/

package string_problems;

import java.util.Arrays;

public class NumberOfLinesToWriteString {
    public static int[] numberOfLines(int[] widths, String s) {
        // step 1 - start with first line and initialize current width
        int lines = 1, currentWidth = 0;

        // step 2 - iterate on each character of string `s`
        for(char ch : s.toCharArray()){
            // step 3 - find corresponding width of current character
            int charWidth = widths[ch - 'a'];
    
            // step 4 - check if adding this character would exceed the line limit
            if(charWidth + currentWidth > 100){
                // start new line
                lines++;
                currentWidth = charWidth;
            }else{
                // otherwise add character to current line
                currentWidth += charWidth;
            }
        }

        // step 5 - return [total number of lines, width of the last line]
        return new int[]{lines, currentWidth};
    }

    public static void main(String[] args) {
        // int[] widths = {10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
        // String s = "abcdefghijklmnopqrstuvwxyz";

        int[] widths = {4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
        String s = "bbbcccdddaaa";
        int[] res = numberOfLines(widths, s);
        System.out.println(Arrays.toString(res));
    }
}