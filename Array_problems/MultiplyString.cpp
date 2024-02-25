
// Problem link - https://leetcode.com/problems/multiply-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.length();
        int n = num2.length();

        // initialize product Array 'productArr' 
        vector<int> product(m+n, 0);

        // now use multiplication algorithm
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                // Calculate positions in the product array
                int p1 = i + j;
                int p2 = i + j + 1;

                // Calculate the product of current digits and add to the ongoing sum
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + product[p2];

                // update product array and carry over if necessary
                product[p1] += (int)sum/10;
                product[p2] = sum % 10;
            }
        }

        //Remove leading zeros and pushback product digits to productRes
        string productRes;
        for(int digit : product){
            if(!(productRes.empty() && digit == 0)){
                productRes.push_back(digit + '0');
            }
        }

        return productRes.empty() ? "0" : productRes;
    }
};