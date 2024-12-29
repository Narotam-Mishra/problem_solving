
#include<bits/stdc++.h>
using namespace std;

vector<int> decrypt(vector<int>& code, int k) {
    int n = code.size();

    // edge case:
    if (k == 0) return vector<int>(n, 0);

    // `res` array to store decrypted code
    vector<int> res(n, 0);

    // find the direction of summation based on `k`
    int direction = k > 0 ? 1 : -1;

    // determine number of elements to sum
    int steps = abs(k);

    for (int i = 0; i < n; i++) {
        // `sum` to store running sum
        int sum = 0;
        for (int j = 1; j <= steps; j++) {
            // calculate the index of the element to sum using modular arithmetic
            int idx = (i + j * direction + n) % n;
            sum += code[idx];
        }
        // store computed sum in result `res` array
        res[i] = sum;
    }
    // return `res` result array
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
    // vector<int> code = {5,7,1,4};
    // int k = 3;

    // vector<int> code = {1,2,3,4};
    // int k = 0;

    vector<int> code = {2,4,9,3};
    int k = -2;
    vector<int> res = decrypt(code, k);
    printVector(res);
    return 0;
}