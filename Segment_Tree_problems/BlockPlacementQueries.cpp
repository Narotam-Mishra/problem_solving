
// Problem link - https://leetcode.com/problems/block-placement-queries/description/?envType=daily-question&envId=2026-05-30

#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach 
vector<bool> getResults1(vector<vector<int>>& queries) {
    // keep track of final result for each type-2 query
    vector<bool> res;

    // using ordered set to keep track of occupied positions after type-1 queries
    set<int> st;

    // step 1 - iterate on each query
    for(auto &query : queries){
        if(query[0] == 1){
            // type-1 query: place a block at position query[1]
            st.insert(query[1]);
        } else {
            // type-2 query: check if there exists a free segment of length sz
            int x = query[1];
            int sz = query[2];

            // `prev` marks the end of the previous occupied position (or start 0)
            int prev = 0;

            // keep track whether a free segment of required length has been found
            bool found = false;

            // step 2 - scan occupied positions in sorted order up to x
            for(int curr : st){
                if(curr > x){
                    // no need to consider positions beyond x
                    break;
                }

                // step 3 - check if the gap between prev and curr can fit sz blocks, 
                if(curr - prev >= sz){
                    // answer is true
                    found = true;
                }

                prev = curr;
            }

            // step 4 - also check the last gap from the final occupied position to x
            if(!found){
                found = (x - prev >= sz);
            }

            // store true or false on the basis of space found
            res.push_back(found);
        }
    }

    // step 5 - return final result, `res`
    return res;
}

// Optimal Approach
vector<bool> getResults(vector<vector<int>>& queries) {
        
}

void printVector(vector<bool>& vec){
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << (vec[i] ? "true" : "false");
        if (i < vec.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
}

int main(){
    // vector<vector<int>> queries = {{1,2},{2,3,3},{2,3,1},{2,2,2}};

    vector<vector<int>> queries = {{1,7},{2,7,6},{1,2},{2,7,5},{2,7,6}};
    vector<bool> res = getResults(queries);
    printVector(res);
    return 0;
}