
// Problem link - https://leetcode.com/problems/maximize-the-minimum-powered-city/?envType=daily-question&envId=2025-11-07

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

// utility function to check if it's possible to achieve minimum power of 'minPower' for all cities
bool canAchieveMinPower(long minPower, vector<ll>& diff, int r, int k, int n){
    vector<ll> tempDiff = diff;

    // iterate through each city to check if minPower is achievable
    ll curPower = 0;
    for(int i=0; i<n; i++){
        // update current city's power using DAT
        curPower += tempDiff[i];

        // if current city has less power than required minimum
        if(curPower < minPower){
            // calculate how many power stations we need to add
            ll psNeed = minPower - curPower;

            // if we don't have enough power stations left, this target is not achievable
            if(psNeed > k){
                return false;
            }

            // use the required power stations
            k -= psNeed;
            curPower += psNeed;

            // using DAT
            if(i + 2*r + 1 < n){
                tempDiff[i+2*r+1] -= psNeed;
            }
        }
    }

    // return true, as successfully achieved minPower for all cities
    return true;
}

ll maxPower(vector<int>& stations, int r, int k) {
    int n = stations.size();

    // step 1 - build initial difference array to calculate power for each city
    // using Difference Array Technique (DAT)
    // diff[i] = the change in power contribution at city i
    vector<ll> diff(n, 0);
    for(int i=0; i<n; i++){
        // range should not be out of index
        diff[max(0, i-r)] += stations[i];

        if(i+r+1 < n){
            diff[i+r+1] -= stations[i];
        }
    }

    // step 2 - using binary search on answer to find maximum possible minimum power
    // lower bound: minimum power any city currently has
    ll s = *min_element(begin(stations), end(stations));
    
    // upper bound: if we place all k stations optimally, maximum possible power
    ll e = accumulate(begin(stations), end(stations), 0LL) + k;

    ll res = 0;
    while(s <= e){
        ll mid = s + (e - s) / 2;

        // check if we can make every city have at least 'mid' power
        if(canAchieveMinPower(mid, diff, r, k, n)){
            // if achievable, try for a higher minimum power
            res = mid;
            s = mid + 1;
        }
        else{
            // if not achievable, try for a lower minimum power
            e = mid - 1;
        }
    }

    // step 3 - return final result, res 
    return res;
}

int main(){
    vector<int> stations = {1,2,4,5,0};
    int r = 1, k = 2;

    // vector<int> stations = {4,4,4,4};
    // int r = 0, k = 3;
    cout<<maxPower(stations, r, k);
    return 0;
}