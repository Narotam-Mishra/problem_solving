
// Problem link : https://leetcode.com/problems/binary-prefix-divisible-by-5/description/?envType=problem-list-v2&envId=bit-manipulation

#include<bits/stdc++.h>
using namespace std;

vector<bool> prefixesDivBy5(vector<int>& nums) {
    vector<bool> res;
    int num = 0;

    for (int i = 0; i < nums.size(); i++) {
        // incrementally build the binary number modulo 5
        num = (num * 2 + nums[i]) % 5;

        // check if divisible by 5
        if (num == 0) {
            res.push_back(true);
        }
        else {
            res.push_back(false);
        }
    }

    return res;
}

int main(){
    vector<int> nums = {0, 1, 1};
    vector<bool> res = prefixesDivBy5(nums);

    for(bool ans : res){
        cout<<ans<<" ";
    }
    cout<<endl;
    return 0;
}