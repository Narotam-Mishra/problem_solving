
// Problem link - https://leetcode.com/problems/maximal-rectangle/description/?envType=daily-question&envId=2026-01-11

#include<bits/stdc++.h>
using namespace std;

// utility function to find NSR
vector<int> findNSR(vector<int>& height){
    int n = height.size();

    stack<int> st;
    vector<int> nsr(n);

    for(int i=n-1; i>=0; i--){
        if(st.empty()){
            nsr[i] = n;
        }else{
            while(!st.empty() && height[st.top()] >= height[i]){
                st.pop();
            }

            if(st.empty()){
                nsr[i] = n;
            }else{
                nsr[i] = st.top();
            }
        }
        st.push(i);
    }

    return nsr;
}

// utility function to find NSL
vector<int> findNSL(vector<int>& height){
    int n = height.size();

    stack<int> st;
    vector<int> nsl(n);

    for(int i=0; i<n; i++){
        if(st.empty()){
            nsl[i] = -1;
        }else{
            while(!st.empty() && height[st.top()] >= height[i]){
                st.pop();
            }

            if(st.empty()){
                nsl[i] = -1;
            }else{
                nsl[i] = st.top();
            }
        }
        st.push(i);
    }

    return nsl;
}

// utility function to find maximum area
int findMaxArea(vector<int>& height){
    // width --> NSR[i] - NSL[i]
    // height -> height[i]

    // find NSR
    vector<int> NSR = findNSR(height);

    // find NSL
    vector<int> NSL = findNSL(height);

    // find width
    int n = height.size();
    vector<int> width(n);
    for(int i=0; i<n; i++){
        width[i] = NSR[i] - NSL[i] - 1;
    }

    // find maximum area
    int maxArea = 0;
    for(int i=0; i<n; i++){
        int area = width[i] * height[i];

        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    // step 1 - find height of 1st rectangle
    vector<int> height(n);
    for(int i=0; i<n; i++){
        height[i] = matrix[0][i] == '1' ? 1 : 0;
    }

    // keep track of maximum area
    int maxArea = findMaxArea(height);

    // step 2 - find height of remaining rectangles
    for(int r=1; r<m; r++){
        for(int c=0; c<n; c++){
            if(matrix[r][c] == '0'){
                height[c] = 0;
            }else{
                height[c] += 1;
            }
        }

        // step 3 - updated maximum area
        maxArea = max(maxArea, findMaxArea(height));
    }

    // step 4 - return maximum area
    return maxArea;
}

int main() {
    // vector<vector<char>> matrix = {
    // {'1','0','1','0','0'},
    // {'1','0','1','1','1'},
    // {'1','1','1','1','1'},
    // {'1','0','0','1','0'}
    // };

    // vector<vector<char>> matrix = {{'0'}};

    vector<vector<char>> matrix = {{'1'}};
    cout << maximalRectangle(matrix);
    return 0;
}