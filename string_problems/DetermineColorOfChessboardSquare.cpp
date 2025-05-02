
#include<bits/stdc++.h>
using namespace std;

bool squareIsWhite(string coordinates) {
    // step 1 - extract character and number from coordinates
    int charVal = coordinates[0] - 'a' + 1;
    int num = coordinates[1] - '0';

    // step 2 - find sum of both co-ordinates
    int sum = charVal + num;

    // step 3 - check whether sum is odd or even and return true and false accordingly
    if(sum % 2 == 0){
        // return false for even sum
        return false;
    }else{
        // return true for odd sum
        return true;
    }
}

int main(){
    // string coordinates = "a1";

    // string coordinates = "h3";

    string coordinates = "c7";
    bool res = squareIsWhite(coordinates);
    res ? cout<<"true" : cout<<"false";
    return 0;
}