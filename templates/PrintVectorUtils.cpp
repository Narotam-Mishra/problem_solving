
#include<bits/stdc++.h>
using namespace std;

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

void printVector1(vector<bool>& vec){
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << (vec[i] ? "true" : "false");
        if (i < vec.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
}

void print2DVector(vector<vector<int>>& matrix){
    cout << "[";
    for (size_t i = 0; i < matrix.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j];
            if (j < matrix[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < matrix.size() - 1) cout << ",";
    }
    cout << "]" << std::endl;
}

int main(){
    vector<vector<int>> grid = {{1,1,0},{1,0,1},{0,0,0}};
    vector<int> nums = {2, 4, 1, 5, 8};
    printVector(nums);
    print2DVector(grid);
    return 0;
}
