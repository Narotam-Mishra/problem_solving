
// Problem link - https://leetcode.com/problems/sum-of-distances/description/?envType=daily-question&envId=2026-04-23

#include<bits/stdc++.h>
using namespace std;

vector<long long> distance(vector<int>& nums) {
        
}

void printVector(vector<long long>& vec){
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
    vector<int> nums = {1,3,1,1,2};
    vector<long long> res = distance(nums);
    printVector(res);
    return 0;
}