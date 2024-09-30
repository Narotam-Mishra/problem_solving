
// Problem link :- https://leetcode.com/problems/flipping-an-image/description/?envType=problem-list-v2&envId=bit-manipulation

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
    // iterate through each row of the image matrix
    for(auto& row : image){
        // start pointer for the row (left side)
        int left = 0;

        // end pointer for the row (right side)
        int right = row.size() - 1;

        // swap and invert simultaneously
        while(left <= right){
            // swap the left and right elements
            // XOR operation: 1 ^ 1 = 0, 0 ^ 1 = 1, so row[left] ^ 1 will invert the value
            int temp = row[left] ^ 1;
            row[left] = row[right] ^ 1;
            row[right] = temp;

            // move pointers towards the center
            left++;
            right--;
        }
    }
    // return the modified image
    return image;
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
    vector<vector<int>> image = {{1,1,0},{1,0,1},{0,0,0}};
    vector<vector<int>> res = flipAndInvertImage(image);
    print2DVector(res);
    return 0;
}