
#include<bits/stdc++.h>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    // step 1: create a map to store the frequency of each element
    unordered_map<int, int> map;
    for(int num : arr){
        map[num]++;
    }

    // step 2 - use an unordered_set to store the unique frequencies
    unordered_set<int> set;
    for(const auto& pair : map){
        set.insert(pair.second);
    }

    // step 3 - compare the size of the set and the map
    return set.size() == map.size();
}

int main(){
    // vector<int> arr = {1,2,2,1,1,3};

    // vector<int> arr = {1,2};

    vector<int> arr = {-3,0,1,-3,1,1,1,-3,10,0};
    bool res = uniqueOccurrences(arr);
    res ? cout<<"true" : cout<<"false";
    return 0;
}