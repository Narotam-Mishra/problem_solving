
// Problem link - https://leetcode.com/problems/lucky-numbers-in-a-matrix/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

vector<int> luckyNumbers(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // store lucky numbers in `luckyNums`
    vector<int> luckyNums;

    // step 1 - loop through each row
    for (int i = 0; i < n; i++) {
        vector<int> row = matrix[i];
        int minVal = row[0];
        int minIndex = 0;

        // step 2 - check minimum element in current row
        for (int j = 1; j < row.size(); j++) {
            if (row[j] < minVal) {
                minVal = row[j];
                minIndex = j;
            }
        }

        // step 3 - check if this min value is also the maximum in its column
        bool isMaxInCol = true;
        for (int k = 0; k < n; k++) {
            if (matrix[k][minIndex] > minVal) {
                isMaxInCol = false;
                break;
            }
        }

        // step 4 - if it is the maximum in column, it's a lucky number
        if (isMaxInCol) {
            luckyNums.push_back(minVal);
        }
    }

    // step 5 - return lucky number array `luckyNums`
    return luckyNums;
}

void printVector(vector<int>& vec){
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout<<vec[i];
        if (i < vec.size() - 1) {
            cout<<",";
        }
    }
    cout<< "]" <<endl;
}

int main(){
    // vector<vector<int>> matrix = {{3,7,8},{9,11,13},{15,16,17}};

    // vector<vector<int>> matrix = {{1,10,4,2},{9,3,8,7},{15,16,17,12}};

    vector<vector<int>> matrix = {{7,8}, {1,2}};
    vector<int> res = luckyNumbers(matrix);
    printVector(res);
    return 0;
}