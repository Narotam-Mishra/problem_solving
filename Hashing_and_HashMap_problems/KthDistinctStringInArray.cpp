
#include<bits/stdc++.h>
using namespace std;

string kthDistinct(vector<string>& arr, int k) {
    // step 1 - count the frequency of each string using a object (map)
    unordered_map<string, int> mp;
    for(int i=0; i<arr.size(); i++) {
        mp[arr[i]]++;
    }

    // step 2 - return the kth distinct string (1-based index)
    for(string str: arr) {
        if(mp[str] == 1) {
            k--;
        }
        if(k == 0) {
            return str;
        }
    }
    return "";
}

int main(){
    // vector<string> arr = {"d","b","c","b","c","a"};
    // int k = 2;

    // vector<string> arr = {"aaa","aa","a"};
    // int k = 1;

    vector<string> arr = {"a","b","a"};
    int k = 3;
    cout<<kthDistinct(arr, k)<<endl;
    return 0;
}