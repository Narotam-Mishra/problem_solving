
#include<bits/stdc++.h>
using namespace std;

bool isHappy(int n) {
    // create a set to store visited numbers for cycle detection
    unordered_set<int> visited;

    // continue process until termination
    while (n != 1 && visited.find(n) == visited.end()) {
        // add current number to visited set
        visited.insert(n);

        // store sum of square of digits in sum
        int sum = 0;

        // calculate sum of squares of digits
        while (n > 0) {
            // extract last digit
            int digit = n % 10;

            // square and add to sum
            sum += digit * digit;

            // extract last digit from number 'n'
            n = (int)n / 10;
        }

        // update n for next iteration
        n = sum;
    }

    // return true if n reached 1 (happy number), false otherwise
    return n == 1;
}

int main(){
    // int num = 19;

    int num = 2;
    bool res = isHappy(num);
    res ? cout<<"true" : cout<<"false"<<endl;
    return 0;
}