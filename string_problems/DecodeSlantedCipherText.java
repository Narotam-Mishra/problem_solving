
// Problem link - https://leetcode.com/problems/decode-the-slanted-ciphertext/description/?envType=daily-question&envId=2026-04-04

package string_problems;

public class DecodeSlantedCipherText {
    public String decodeCiphertext(String encodedText, int rows) {
        int len = encodedText.length();

        // step 1 - find number of column
        int col = len / rows;

        // step 2 - iterate diagonally
        StringBuilder originalText = new StringBuilder();

        for (int c = 0; c < col; c++) {
            for (int j = c; j < len; j += (col + 1)) {
                // step 3 - build string
                originalText.append(encodedText.charAt(j));
            }
        }

        // step 4 - remove trailing spaces
        int i = originalText.length() - 1;
        while (i >= 0 && originalText.charAt(i) == ' ') {
            originalText.deleteCharAt(i);
            i--;
        }

        // step 5 - return result
        return originalText.toString();
    }

    public static void main(String[] args) {
        DecodeSlantedCipherText obj = new DecodeSlantedCipherText();
        String encodedText = "ch   ie   pr";
        int rows = 3;
        System.out.println(obj.decodeCiphertext(encodedText, rows));
    }
}
