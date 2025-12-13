
// Problem link - https://leetcode.com/problems/coupon-code-validator/description/?envType=daily-question&envId=2025-12-13

#include<bits/stdc++.h>
using namespace std;

// utility function to check if a coupon code is valid
bool isValidCode(const string& code) {
    if (code.empty()) return false;
    for (char ch : code) {
        if (!isalnum(ch) && ch != '_') {
            return false;
        }
    }
    return true;    
}

vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
    // map to store business line and its priorities
    unordered_map<string, int> mp = {
        {"restaurant", 3},
        {"grocery", 1},
        {"pharmacy", 2},
        {"electronics", 0}
    };

    // {code, index}
    vector<pair<int, string>> res;

    // step 1 - validate coupons and make pair of {priority, code}
    for(int i=0; i<code.size(); i++){
        if(isActive[i] && mp.count(businessLine[i]) && isValidCode(code[i])){
            res.push_back({mp[businessLine[i]], code[i]});
        }
    }

    // step 2 - sort based on priority and lex order
    sort(res.begin(), res.end());

    // step 3 - extract only codes
    vector<string> ans;
    for(auto& p : res){
        ans.push_back(p.second);
    }

    // step 4 - return the result, `res`
    return ans;
}

void printVector(vector<string>& vec){
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
    // vector<string> code = {"SAVE20", "", "PHARMA5", "SAVE@20"};
    // vector<string> businessLine = {"restaurant","grocery","pharmacy","restaurant"};
    // vector<bool> isActive = {true, true, true, true};

    vector<string> code = {"GROCERY15","ELECTRONICS_50","DISCOUNT10"};
    vector<string> businessLine = {"grocery","electronics","invalid"};
    vector<bool> isActive = {false, true, true};

    vector<string> res = validateCoupons(code, businessLine, isActive);
    printVector(res);
    return 0;
}