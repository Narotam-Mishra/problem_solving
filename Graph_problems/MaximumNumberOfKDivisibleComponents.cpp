
// Problem link - https://leetcode.com/problems/maximum-number-of-k-divisible-components/description/?envType=daily-question&envId=2025-11-28

#include<bits/stdc++.h>
using namespace std;

int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        
}

int main(){
    int n = 5;
    vector<vector<int>> edges = {{0,2},{1,2},{1,3},{2,4}};
    vector<int> values = {1,8,1,4,4};
    int k = 6;
    cout<<maxKDivisibleComponents(n, edges, values, k);
}