
// Problem link : https://leetcode.com/problems/excel-sheet-column-title/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

package NumberTheory_Problems;

public class ExcelSheetColumnTitle {
    public static String convertToTitle(int columnNumber) {
        StringBuilder title = new StringBuilder();

        while (columnNumber > 0) {
            // for adjusting for 1-based indexing
            columnNumber--;

            // calculate the current letter
            char letter = (char)((columnNumber % 26) + 'A');

            // prepend the letter to the title
            title.insert(0, letter);

            // move to the next position
            columnNumber /= 26;
        }

        return title.toString();
    }

    public static void main(String[] args) {
        // int columnNumber = 1;

        // int columnNumber = 26;

        // int columnNumber = 27;

        int columnNumber = 28;
        System.out.println(convertToTitle(columnNumber));
    }
}