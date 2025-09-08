
// Problem link - https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/?envType=daily-question&envId=2025-09-08

#include<bits/stdc++.h>
using namespace std;

// utility function whether number `num` has zero or not
bool hasZero(int n){
    return to_string(n).find('0') != string::npos;
}

vector<int> getNoZeroIntegers(int n) {
    // step 1 - start with a = 1 and b = n-1
    int a = 1;
    int b = n - 1;

    // step 2 - keep searching until we find a valid pair
    // since a solution is guaranteed, this loop will terminate
    while (hasZero(a) || hasZero(b)) {
        // try next value of `a`
        a++;

        // update `b` to maintain sum
        b = n - a;
    }

    // step 3 - return required numbers `a` and `b`
    return { a, b };
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
    // int n = 2;

    int n = 11;
    vector<int> res = getNoZeroIntegers(n);
    printVector(res);
    return 0;
}