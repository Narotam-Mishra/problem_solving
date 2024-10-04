
// Problem link : https://leetcode.com/problems/decode-xored-array/description/?envType=problem-list-v2&envId=bit-manipulation&favoriteSlug=&status=TO_DO&difficulty=EASY

// Key Concept : Inverse of XOR is XOR itself

#include<bits/stdc++.h>
using namespace std;

vector<int> decode(vector<int>& encoded, int first) {
    int n = encoded.size();
    vector<int> arr(n+1, 0);

    // initialize the original array with the first element.
    arr[0] = first;

    // reconstruct the rest of the array using the encoded values.
    for(int i=0; i<n; i++){
        arr[i+1] = encoded[i] ^ arr[i];
    }
    // return required array 'arr'
    return arr;
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
    vector<int> nums = {1, 2, 3};
    int first = 1;
    vector<int> res = decode(nums, first);
    printVector(res);
    return 0;
}