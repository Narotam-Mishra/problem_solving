
// Problem link - https://leetcode.com/problems/final-value-of-variable-after-performing-operations/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

int finalValueAfterOperations(vector<string>& operations) {
    // step 1 - set initial to 0
    int val = 0;

    // step 2 - iterate on each operation and perform accordingly
    for (string op : operations) {
        // perform operation
        if (op == "--X" || op == "X--") {
            val--;
        }
        else {
            val++;
        }
    }

    // step 3 - return final value after all operations
    return val;
}

int main(){
    vector<string> operations = {"--X","X++","X++"};
    cout<<finalValueAfterOperations(operations)<<endl;
    return 0;
}