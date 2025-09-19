
// Problem link - https://leetcode.com/problems/design-spreadsheet/?envType=daily-question&envId=2025-09-19

#include<bits/stdc++.h>
using namespace std;

class Spreadsheet {
    // using 2D-vector as grid
    vector<vector<int>> sheet;
public:

    Spreadsheet(int rows) {
        // initialize sheet
        sheet.assign(rows, vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        // find row and column from cell
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;

        // set the value
        sheet[row][col] = value;
    }
    
    void resetCell(string cell) {
        // find row and column from cell
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;

        // reset cell value to 0
        sheet[row][col] = 0;
    }

    int extractValue(const string& str){
        // check if str is number
        if(isdigit(str[0])){
            // convert it into number and return
            return stoi(str);
        }

        // otherwise find row and column from cell
        int col = str[0] - 'A';
        int row = stoi(str.substr(1)) - 1;
        return sheet[row][col];
    }
    
    int getValue(string formula) {
        // extract "X + Y" from "=X+Y"
        string s = formula.substr(1);

        // find X and Y from "X+Y" expression
        int plusIndex = s.find('+');
        string leftVal = s.substr(0, plusIndex);
        string rightVal = s.substr(plusIndex+1);

        // evaluate X+Y and return the value
        return extractValue(leftVal) + extractValue(rightVal);
    }
};

int main(){
    // create a spreadsheet with 5 rows
    Spreadsheet obj(5);
    
    // test setting cells
    obj.setCell("A1", 10);
    obj.setCell("B2", 20);
    obj.setCell("C3", 15);
    
    cout << "Testing Spreadsheet Operations:" << endl;
    
    // test getValue with cell references
    cout << "A1 + B2 = " << obj.getValue("=A1+B2") << endl; // Should output 30
    cout << "B2 + C3 = " << obj.getValue("=B2+C3") << endl; // Should output 35
    
    // test getValue with numbers
    cout << "A1 + 5 = " << obj.getValue("=A1+5") << endl;   // Should output 15
    cout << "10 + B2 = " << obj.getValue("=10+B2") << endl; // Should output 30
    
    // test resetCell
    obj.resetCell("A1");
    cout << "After resetting A1:" << endl;
    cout << "A1 + B2 = " << obj.getValue("=A1+B2") << endl; // Should output 20
    
    // test with mixed operations
    obj.setCell("D4", 25);
    cout << "C3 + D4 = " << obj.getValue("=C3+D4") << endl; // Should output 40
    return 0;
}