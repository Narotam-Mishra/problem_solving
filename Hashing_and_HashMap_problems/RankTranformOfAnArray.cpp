
// Problem link : https://leetcode.com/problems/rank-transform-of-an-array/description/?envType=problem-list-v2&envId=hash-table

#include<bits/stdc++.h>
using namespace std;

vector<int> arrayRankTransform(vector<int>& arr) {
    // step 1 - Pair elements with their original indices
    vector<pair<int, int>> pairs(arr.size());
    for (int i = 0; i < arr.size(); i++) {
        pairs[i] = { arr[i], i };
    }

    // step 2 - sort the array by its value
    sort(pairs.begin(), pairs.end());

    // step 3 - assign ranks
    vector<int> ranks(arr.size());
    int rank = 1;
    for (int i = 0; i < pairs.size(); i++) {
        // if the current value is not equal to the previous value,
        if (i > 0 && pairs[i].first != pairs[i - 1].first) {
            // incremnt the rank
            rank++;
        }
        // otherwise assign the same rank
        ranks[pairs[i].second] = rank;
    }

    // step 4 - return ranks
    return ranks;
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
    // vector<int> arr = {40,10,20,30};

    // vector<int> arr = {100, 100, 100};

    vector<int> arr = {37,12,28,9,100,56,80,5,12};
    vector<int> res = arrayRankTransform(arr);
    printVector(res);
    return 0;
}