
#include<bits/stdc++.h>
using namespace std;

vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    // step 1 - create a vector of indices
    vector<int> indices(heights.size());
    for(int i = 0; i < heights.size(); i++){
        indices[i] = i;
    }

    // step 2 - sort indices based on heights in descending order
    sort(indices.begin(), indices.end(), [&](int a, int b){
        return heights[a] > heights[b];
    });

    // step 3 - create the result vector using sorted indices
    vector<string> res;
    for(int i : indices){
        res.push_back(names[i]);
    }

    // step 4 - return resultant `res` vector
    return res;
}

void printVector(vector<string>& vec){
    cout << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        cout<<vec[i];
        if (i < vec.size() - 1) {
            cout<<",";
        }
    }
    cout<< "]" <<endl;
}
int main(){
    vector<string> names = {"Mary","John","Emma"};
    vector<int> heights = {180, 165, 170};
    vector<string> res = sortPeople(names, heights);
    printVector(res);
    return 0;
}