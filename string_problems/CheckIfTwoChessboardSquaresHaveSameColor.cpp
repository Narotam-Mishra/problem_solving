
// Problem link - https://leetcode.com/problems/check-if-two-chessboard-squares-have-the-same-color/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

bool checkTwoChessboards(string coordinate1, string coordinate2) {
    // step 1 - extract character and number from coordinate
    int charVal1 = coordinate1[0] - 'a' + 1;
    int num1 = coordinate1[1] - '0';

    int charVal2 = coordinate2[0] - 'a' + 1;
    int num2 = coordinate2[1] - '0';

    // step 2 - find sum of both co-ordinates
    int sum1 = charVal1 + num1;
    int sum2 = charVal2 + num2;

    // step 3 - check if both sum are either even or odd then return true, otherwise return false
    if (sum1 % 2 == 0 && sum2 % 2 == 0) {
        return true;
    }
    else if (sum1 % 2 != 0 && sum2 % 2 != 0) {
        return true;
    }
    else {
        return false;
    }
}

int main(){
    // string coordinate1 = "a1", coordinate2 = "c3";

    string coordinate1 = "a1", coordinate2 = "h3";
    bool res = checkTwoChessboards(coordinate1, coordinate2);
    res ? cout<<"true" : cout<<"false";
    return 0;
}