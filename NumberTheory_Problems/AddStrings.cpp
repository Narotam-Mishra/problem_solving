
#include<bits/stdc++.h>
using namespace std;

string addStrings(string num1, string num2) {
    // initialize variables 'res' and 'carry' to store the result and the carry
    string res = "";
    int carry = 0;

    // initialize pointers for num1 and num2
    int i = num1.size() - 1;
    int j = num2.size() - 1;

    // loop through num1 and num2 from right to left
    while (i >= 0 || j >= 0) {
        // calculate the sum of the current digits and the carry
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';

        // update result 'res' and carry
        res = to_string(sum % 10) + res;
        carry = (int)sum / 10;
    }

    // if there's still a carry, add it to the result
    if (carry > 0) res = to_string(carry) + res;
    return res;
}

int main(){
    // string num1 = "11", num2 = "123";

    // string num1 = "456", num2 = "77";

    string num1 = "0", num2 = "0";
    cout<<addStrings(num1, num2);
    return 0;
}

