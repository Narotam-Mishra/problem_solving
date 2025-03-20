
#include<bits/stdc++.h>
using namespace std;

bool isBalanced(string num) {
    // step 1 - initialize variables to store even and odd indices sum
    int evenSum = 0, oddSum = 0;

    // step 2 - iterate on `num`
    for(int i=0; i<num.size(); i++){
        // use 1-based indexing
        int index = i+1;
        // check for even index
        if(index % 2 == 0){
            // step 3 - find even index sum
            evenSum += (num[i] - '0');
        }else{
            // step 4 - find odd index sum
            oddSum += (num[i] - '0');
        }
    }

    // step 5 - if even index sum equals to odd index sum then return true otherwise false
    return evenSum == oddSum;
}

int main(){
    // string num = "1234";

    string num = "24123";
    bool res = isBalanced(num);
    res ? cout<<"true" : cout<<"false";
    return 0;
}