
#include<bits/stdc++.h>
using namespace std;

vector<int> getSneakyNumbers(vector<int>& nums) {
    // step 1 - initialize result vector to store sneaky numbers
    vector<int> res;
    unordered_set<int> seen;

    // step 2 - iterate through the list of numbers
    for(int num : nums){
        // step 3 - check for duplicate
        if(seen.find(num) != seen.end()){
            // step 4 - store sneaky numbers
            res.push_back(num);
        }else{
            seen.insert(num);
        }
    }

    // step 5 - return result
    return res;
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
    // vector<int> nums = {0,3,2,1,3,2};

    // vector<int> nums = {0,1,1,0};

    vector<int> nums = {7,1,5,4,3,4,6,0,9,5,8,2};
    vector<int> res = getSneakyNumbers(nums);
    printVector(res);
    return 0;
}