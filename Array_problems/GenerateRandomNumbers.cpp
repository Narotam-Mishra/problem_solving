
// Generate random numbers each time

#include<bits/stdc++.h>
using namespace std;

int main(){
    // using time() to seed the srand() function with differnt value each instance of time
    srand(time(NULL));
    int len = 10;
    while(len > 0){
        cout<<"Random Number: "<<rand() % 100<<endl;
        len--;
    }
}