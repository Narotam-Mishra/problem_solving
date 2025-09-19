
// Problem link - https://leetcode.com/problems/design-spreadsheet/?envType=daily-question&envId=2025-09-19

package Design_problems;

class Spreadsheet {
    // using 2D array as grid
    private int[][] sheet;

    public Spreadsheet(int rows) {
        // initilaization
        sheet = new int[rows][26];
    }
    
    public void setCell(String cell, int value) {
        // find row and column from cell
        int col = cell.charAt(0) - 'A';
        int row = Integer.parseInt(cell.substring(1)) - 1;

        // set the value
        sheet[row][col] = value;
    }
    
    public void resetCell(String cell) {
        // find row and column from cell
        int col = cell.charAt(0) - 'A';
        int row = Integer.parseInt(cell.substring(1)) - 1;

        // reset the value
        sheet[row][col] = 0;
    }

    private int extractValue(String str){
        // check if str is number
        if(Character.isDigit(str.charAt(0))){
            // convert it into number and return
            return Integer.parseInt(str);
        }

        // otherwise find row and column from str
        int col = str.charAt(0) - 'A';
        int row = Integer.parseInt(str.substring(1)) - 1;
        return sheet[row][col];
    }
    
    public int getValue(String formula) {
        // remove "=" from "=X+Y" expression
        String s = formula.substring(1);

        // find X and Y from "X+Y" expression
        int plusIndex = s.indexOf('+');
        String leftVal = s.substring(0, plusIndex);
        String rightVal = s.substring(plusIndex+1);

        // evaluate X+Y and return the value
        return extractValue(leftVal) + extractValue(rightVal);
    }
}

public class DesignSpreadsheet {
    public static void main(String[] args) {
        // create a spreadsheet with 5 rows
        Spreadsheet obj = new Spreadsheet(5);
        
        // test setting cells
        obj.setCell("A1", 10);
        obj.setCell("B2", 20);
        obj.setCell("C3", 15);
        
        System.out.println("Testing Spreadsheet Operations:");
        
        // test getValue with cell references
        System.out.println("A1 + B2 = " + obj.getValue("=A1+B2")); // Should output 30
        System.out.println("B2 + C3 = " + obj.getValue("=B2+C3")); // Should output 35
        
        // test getValue with numbers
        System.out.println("A1 + 5 = " + obj.getValue("=A1+5"));   // Should output 15
        System.out.println("10 + B2 = " + obj.getValue("=10+B2")); // Should output 30
        
        // test resetCell
        obj.resetCell("A1");
        System.out.println("After resetting A1:");
        System.out.println("A1 + B2 = " + obj.getValue("=A1+B2")); // Should output 20
        
        // test with mixed operations
        obj.setCell("D4", 25);
        System.out.println("C3 + D4 = " + obj.getValue("=C3+D4")); // Should output 40
    }
}