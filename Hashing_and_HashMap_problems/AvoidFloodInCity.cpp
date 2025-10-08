
// Problem link - https://leetcode.com/problems/avoid-flood-in-the-city/?envType=daily-question&envId=2025-10-07

#include<bits/stdc++.h>
using namespace std;

vector<int> avoidFlood1(vector<int>& rains) {
    // get the total number of days
    int n = rains.size();

    // vector to store indices of dry days (when rains[i] == 0)
    // these are the days we can choose to dry a lake
    vector<int> dryDays;

    // map to track which lakes are currently full
    // key: lake number, value: the day index when it was last filled
    unordered_map<int, int> filledLakes;

    // result vector to store our answer
    vector<int> res(n);

    // step 1 - process each day sequentially
    for (int i = 0; i < n; i++) {
        int lake = rains[i];

        // step 2 - case 1: DRY DAY (rains[i] == 0)
        if (lake == 0) {
            // store this day index as an available dry day
            // we might need it later to prevent a flood
            dryDays.push_back(i);

            // set placeholder value (dry lake 1 by default)
            // this will be overwritten if we need to use this day
            res[i] = 1;
        }
        // step 3 - case 2: RAINY DAY (rains[i] > 0)
        else {
            // check if this lake is already full
            if (filledLakes.find(lake) != filledLakes.end()) {
                // FLOOD ALERT! This lake is already full
                // we must have dried it using a dry day that occurred

                // step 4 - get the day when this lake was last filled
                int lastFilledIndex = filledLakes[lake];

                // variable to store the dry day we'll use to prevent flood
                int index = -1;

                // iterator to track which dry day to remove
                int removeIdx = -1;

                // step 5 - search through available dry days to find one that occurred
                // after the lake was last filled
                for (int j = 0; j < dryDays.size(); j++) {
                    // check if this dry day is after the lake was filled
                    if (dryDays[j] > lastFilledIndex) {
                        // found a valid dry day!
                        index = dryDays[j];
                        removeIdx = j;
                        break;
                    }
                }

                // step 6 - if no valid dry day was found, flood is inevitable
                if (index == -1) {
                    // return empty vector to indicate impossible scenario
                    return {};
                }

                // step 7 - assign this dry day to dry the specific lake
                // that would have caused a flood
                res[index] = lake;

                // step 8 - remove this dry day from available list
                dryDays.erase(dryDays.begin() + removeIdx);
            }

            // step 9 - mark this lake as full (or update fill time)
            // store current day as the last time this lake was filled
            filledLakes[lake] = i;

            // step 10 - for rainy days, the answer is always -1
            res[i] = -1;
        }
    }

    // step 11 - return the final result vector
    return res;
}

vector<int> avoidFlood(vector<int>& rains) {
    int n = rains.size();

    // lake -> first day rain
    unordered_map<int, int> rainDay;

    // set to store zero days for best lookup
    set<int> zeroDays;

    // store final result in `res`
    vector<int> res(n, -1);

    for(int i=0; i<n; i++){
        int lake = rains[i];

        if(lake == 0){
            zeroDays.insert(i);
        }
        else{
            res[i] = -1;

            // also check if this lake already has water,
            // if yes then we will check if we can dry it up
            if(rainDay.count(lake)){
                // already has water
                // so find the first zero day to dry it up
                auto it = zeroDays.lower_bound(rainDay[lake]);

                // check if no zero day exist
                if(it == zeroDays.end()){
                    // then it will cause flood
                    return {}; 
                }

                // day on which no rain happened
                int zerothDay = *it;
                res[zerothDay] = lake;

                // since this zero day is utlised , so remove it
                zeroDays.erase(it);
            }

            // store entry in map - ith day it ran on lake
            rainDay[lake] = i;
        }
    }

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
    // vector<int> rains = {1,2,3,4};

    // vector<int> rains = {1,2,0,0,2,1};

    vector<int> rains = {1,2,0,1,2};
    vector<int> res = avoidFlood(rains);
    printVector(res);
    return 0;
}