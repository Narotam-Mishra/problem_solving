
#include<bits/stdc++.h>
using namespace std;

bool isFascinating(int n) {
    // directly return true if n is one of the only four fascinating numbers
    return n == 192 || n == 219 || n == 273 || n == 327;
}

int main(){
    // int n = 192;

    int n = 100;
    bool res = isFascinating(n);
    res ? cout<<"true" : cout<<"false";
    return 0;
}