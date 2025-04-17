
// Problem link - https://leetcode.com/problems/sum-of-digits-of-string-after-convert/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

int getLucky(string s, int k) {
    // step 1 - convert each character in the string to its corresponding position in the alphabet
    // and calculate the sum of its digits
    int sum = 0;
    for(char ch : s){
        int digit = ch - 'a' + 1;
        sum += digit / 10 + digit % 10;
    }

    // step 2 - perform the transformation k-times
    for(int i=1; i<k; i++){
        int nextSum = 0;
        while(sum > 0){
            nextSum += sum%10;
            sum = sum/10;
        }
        sum = nextSum;
    }

    // step 3 - return the final sum
    return sum;
}

int main(){
    // string s = "iiii";
    // int k = 1;

    // string s = "leetcode";
    // int k = 2;

    string s = "zbax";
    int k = 2;
    cout<<getLucky(s, k)<<endl;
    return 0;
}

