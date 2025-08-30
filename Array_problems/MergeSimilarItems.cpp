
// Problem link - https://leetcode.com/problems/merge-similar-items/

#include<bits/stdc++.h>
using namespace std;

// helper function to process items
void processItems(vector<vector<int>>& items, map<int, int>& valueWeightMap){
    for(vector<int> item : items){
        int value = item[0];
        int weight = item[1];

        // add weight to existing value or create new entry
        valueWeightMap[value] += weight;
    }
}

vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
    // step 1 - using map to automatically maintain sorted order by key (value)
    map<int, int> valueWeightMap;

    // step 2 - process items
    processItems(items1, valueWeightMap);
    processItems(items2, valueWeightMap);

    // step 3 - convert map to vector of vectors
    vector<vector<int>> res;

    // reserve space for resultant vector `res`
    res.reserve(valueWeightMap.size());

    for(const auto& pair : valueWeightMap){
        res.push_back({pair.first, pair.second});
    }

    // step 4 - return final result `res`
    return res;
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
    // vector<vector<int>> items1 = {{1,1},{4,5},{3,8}}, items2 = {{3,1},{1,5}};

    // vector<vector<int>> items1 = {{1,1},{3,2},{2,3}}, items2 = {{2,1},{3,2},{1,3}};

    vector<vector<int>> items1 = {{1,3},{2,2}}, items2 = {{7,1},{2,2},{1,4}};
    
    vector<vector<int>> res = mergeSimilarItems(items1, items2);
    print2DVector(res);
    return 0;
}