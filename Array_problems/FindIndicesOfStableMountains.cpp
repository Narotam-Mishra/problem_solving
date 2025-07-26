
// Problem link - https://leetcode.com/problems/find-indices-of-stable-mountains/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

vector<int> stableMountains(vector<int>& height, int threshold) {
    // store stable mountain indices in `stableMountains`
    vector<int> stableMountains;

    // step 1 - start from index 1 since mountain 0 cannot be stable
    // as no mountain exists before index 0
    for (int i = 1; i < height.size(); i++) {
        // step 2 - check if the previous mountain is stable
        if (height[i - 1] > threshold) {
            // step 3 - add current mountain's index to result
            stableMountains.push_back(i);
        }
    }

    // step 4 - return stable mountain indices
    return stableMountains;
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
    // vector<int> height = {1,2,3,4,5};
    // int threshold = 2;

    // vector<int> height = {10,1,10,1,10};
    // int threshold = 3;

    vector<int> height = {10,1,10,1,10};
    int threshold = 10;
    vector<int> res = stableMountains(height, threshold);
    printVector(res);
    return 0;
}