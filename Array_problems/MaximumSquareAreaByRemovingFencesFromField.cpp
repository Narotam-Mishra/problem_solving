
// Problem link - https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/description/

#include<bits/stdc++.h>
using namespace std;

int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
    const int mod = 1e9+7;

    // step 1 - insert 1 to hFences & vFences to find all widths
    vFences.push_back(1);
    vFences.push_back(n);

    hFences.push_back(1);
    hFences.push_back(m);

    // sort both fences
    sort(hFences.begin(), hFences.end());
    sort(vFences.begin(), vFences.end());

    // step 2 - find all widths for vFences
    unordered_set<int> widths;
    for(int i=0; i<vFences.size(); i++){
        for(int j=i+1; j<vFences.size(); j++){
            int w = vFences[j] - vFences[i];
            widths.insert(w);
        }
    }
    
    // step 3 - find all heights for hFences
    int maxSide = 0;
    for(int i=0; i<hFences.size(); i++){
        for(int j=i+1; j<hFences.size(); j++){
            int h = hFences[j] - hFences[i];
            if(widths.find(h) != widths.end()){
                maxSide = max(maxSide, h);
            }
        }
    }

    // step 4 - return area using maximum side
    return maxSide == 0 ? -1 : (1LL * maxSide * maxSide) % mod;
}

int main(){
    // int m = 4, n = 3;
    // vector<int> hFences = {2,3}, vfences = {2};

    int m = 6, n = 7;
    vector<int> hFences = {2}, vfences = {4};
    cout<<maximizeSquareArea(m,n,hFences,vfences);
    return 0;
}

