
// Problem link - https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

#include<bits/stdc++.h>
using namespace std;

vector<int> findMissingAndRepeatingNumber(vector<int>& arr, int n) {
    int missingNum = 0, repeatingNum = 0;

    vector<int> frqMap(n+1, 0);
    for(int i=0; i<n; i++){
        // count frquency
        frqMap[arr[i]]++;
    }

    for(int i=1; i<=n; i++){
        if(frqMap[i] == 0){
            missingNum = i;
        }else if(frqMap[i] == 2){
            repeatingNum = i;
        }
    }

    return {repeatingNum, missingNum};
}

int main(){
    vector<int> arr = {1, 3, 3};
    vector<int> ans = findMissingAndRepeatingNumber(arr, arr.size());
    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}