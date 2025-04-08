
#include<bits/stdc++.h>
using namespace std;

vector<int> diStringMatch(string s) {
    // step 1 - intialize all necessary variables and store result into `res`
    int n = s.size();
    int low = 0;
    int high = n;
    vector<int> res(n+1, 0); 

    // step 2 - iterate on `s`
    for (int i = 0; i < n; i++) {
        if (s[i] == 'I') {
            // step 3 - if 'I', assign the lowest number and increment low
            res[i] = low;
            low++;
        } else {
            // step 4 - if 'D', assign the highest number and decrement high
            res[i] = high;
            high--;
        }
    }

    // step 5 - after the loop, one number (low === high) remains to be added
    res[n] = low;

    // step 6 - return `res`
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
    // string s = "IDID";

    // string s = "III";

    string s = "DDI";
    vector<int> res = diStringMatch(s);
    printVector(res);
    return 0;
}