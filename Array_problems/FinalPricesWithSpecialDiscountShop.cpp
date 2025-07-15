
// Problem link - https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

vector<int> finalPrices(vector<int>& prices) {
    // store result in `res` array
    int n = prices.size();
    vector<int> res(n, 0);

    // step 1 - for each item in the shop
    for (int i = 0; i < n; i++) {
        int discount = 0;

        // step 2 - look for the first item to the right with price <= current price
        for (int j = i + 1; j < n; j++) {
            // step 3 - found discount
            if (prices[j] <= prices[i]) {
                // take only first discount
                discount = prices[j];
                break;
            }
        }

        // step 4 - calculate the discounted price
        res[i] = prices[i] - discount;
    }

    // step 5 - return resultant discount array `res`
    return res;
}

void printVector(vector<int>& vec){
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout<<vec[i];
        if (i < vec.size() - 1) {
            cout<<",";
        }
    }
    cout<< "]" <<endl;
}

int main(){
    // vector<int> prices = {8,4,6,2,3};

    // vector<int> prices = {1,2,3,4,5};

    vector<int> prices = {10,1,1,6};
    vector<int> res = finalPrices(prices);
    printVector(res);
    return 0;
}