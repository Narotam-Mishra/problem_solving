
// Problem link - https://leetcode.com/problems/count-number-of-trapezoids-i/description/?envType=daily-question&envId=2025-12-02

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int countTrapezoids(vector<vector<int>>& points) {
    const int mod = 1e9 + 7;

    // step 1 - find count of horizintal lines
    unordered_map<int, int> mp;
    for(auto &point : points){
        int y = point[1];
        mp[y]++;
    }

    // step 2 - count trapezoids
    ll res = 0, prevHl= 0;
    for(auto &it : mp){
        int count = it.second;

        // countC2
        ll hLines = (ll) count * (count - 1) / 2;

        res += hLines * prevHl;

        prevHl += hLines;
    }

    // step 3 - return final result, `res`
    return res % mod;
}

int main(){
    vector<vector<int>> points = {{1,0},{2,0},{3,0},{2,2},{3,2}};
    cout<<countTrapezoids(points);
    return 0;
}