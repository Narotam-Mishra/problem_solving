
#include<bits/stdc++.h>
using namespace std;

bool checkIfExist(vector<int>& arr) {
    // step 1 - initialize a Set to store elements we have seen so far
    unordered_set<int> seen;
    
    // step 2 - iterate through the array
    for(int num : arr) {
        // step 2.1 - check if num / 2 exists in the set (for arr[i] = 2 * arr[j])
        if (seen.count(num / 2) && num % 2 == 0) {
            return true;
        }

        // step 2.2 - check if 2 * num exists in the set (for arr[j] = num / 2)
        if (seen.count(num * 2)) {
            return true;
        }
        // step 3 - add the current number to the set
        seen.insert(num);
    }
    // step 4 - if no such pair is found, return false
    return false;
}

int main(){
    // vector<int> arr = {10, 2, 5, 3};

    vector<int> arr = {3,1,7,11};
    bool res = checkIfExist(arr);
    res ? cout<<"true" : cout<<"false"<<endl;
    return 0;
}