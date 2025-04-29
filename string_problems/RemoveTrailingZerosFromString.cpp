
// Problem link - https://leetcode.com/problems/remove-trailing-zeros-from-a-string/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

string removeTrailingZeros(string num) {
    // step 1 - initialize counter to count trailing zeros in `num`
    int countZeros = 0;
    int n = num.size();

    // step 2 - iterate on `num` from backward to find trailing zeros easily
    for(int i=n-1; i>=0; i--){
        // count trailing zeros
        if(num[i] == '0'){
            countZeros++;
        }else{
            // for non zeros break the loop
            break;
        }
    }

    // step 3 - return substring of `num` after removing trailing zeros
    return num.substr(0, n - countZeros);
}

int main(){
    // string num = "51230100";

    string num = "123";
    cout<<removeTrailingZeros(num)<<endl;
    return 0;
}