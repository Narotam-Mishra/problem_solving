
// Problem link - https://leetcode.com/problems/relative-sort-array/description/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    // step 1 - create frequency array to count occurrences of each number
    vector<int> frq(1001);
    for (int num : arr1) {
        frq[num]++;
    }

    // store result in `res`
    vector<int> res(arr1.size());

    // step 2 -  first, place all elements that appear in arr2 in the order specified by arr2
    int idx = 0;
    for (int num : arr2) {
        while (frq[num]-- > 0) {
            res[idx++] = num;
        }
    }

    // step 3 - Place remaining elements (not in arr2) in ascending order
    for (int i = 0; i < 1001; i++) {
        while (frq[i]-- > 0) {
            res[idx++] = i;
        }
    }

    // step 4 - return the relatively sorted array
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
    // vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    // vector<int> arr2 = {2,1,4,3,9,6};

    vector<int> arr1 = {28,6,22,8,44,17};
    vector<int> arr2 = {22,28,8,6};
    vector<int> res = relativeSortArray(arr1, arr2);
    printVector(res);
    return 0;
}
