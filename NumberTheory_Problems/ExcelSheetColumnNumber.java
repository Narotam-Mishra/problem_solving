
// Problem link : https://leetcode.com/problems/excel-sheet-column-number/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

package NumberTheory_Problems;

public class ExcelSheetColumnNumber {
    public static int titleToNumber(String columnTitle) {
        // intialize columnNumber to 0 and store actual result in it, 
        int columnNumber = 0;

        // iterate on each character of column title
        for(int i=0; i<columnTitle.length(); i++) {
            // shift columnNumber up by 26 for the new place
            columnNumber *= 26;

            // add the value of the current character (A=1, B=2, ..., Z=26)
            columnNumber += columnTitle.charAt(i) - 'A' + 1;
        }

        // return actual result
        return columnNumber;
    }

    public static void main(String[] args) {
        // String ct = "A";

        // String ct = "AB";

        String ct = "ZY";
        System.out.println(titleToNumber(ct));
    }
}