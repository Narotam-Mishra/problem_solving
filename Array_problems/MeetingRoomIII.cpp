
// Problem link - https://leetcode.com/problems/meeting-rooms-iii/?envType=daily-question&envId=2025-12-27

#include<bits/stdc++.h>
using namespace std;

int mostBooked(int n, vector<vector<int>>& meetings) {
    int m = meetings.size();

    // step 1 - sort mettings by their start time,
    sort(begin(meetings), end(meetings));

    // lastAvailable[i] = time when room i becomes free
    vector<long long> lastAvailable(n, 0);

    // keep track of how many times rooms have been used
    vector<int> roomsUsedCount(n, 0);

    // step 2 - process each meeting
    for(auto& meet : meetings){
        int sTime = meet[0];
        int eTime = meet[1];
        int meetDuration = eTime - sTime;

        long long earliestFreeTime = LLONG_MAX;
        int earliestRoom = 0;
        bool roomAssigned = false;

        // step 3 - find free room
        for(int r=0; r<n; r++){
            // check if room is free at meeting start time
            if(lastAvailable[r] <= sTime && !roomAssigned){
                // assign meeting
                lastAvailable[r] = eTime;
                roomsUsedCount[r]++;
                roomAssigned = true;
            }

            // track room that becomes free earliest
            if(lastAvailable[r] < earliestFreeTime){
                earliestFreeTime = lastAvailable[r];
                earliestRoom = r;
            }
        }

        // step 4 - if no room was free, dealy meeting
        if(!roomAssigned){
            lastAvailable[earliestRoom] += meetDuration;
            roomsUsedCount[earliestRoom]++;
        }
    }

    // step 5 - find room with maximum usage and return it
    int resRoom = -1;
    int maxUse = 0;
    for(int r=0; r<n; r++){
        if(roomsUsedCount[r] > maxUse){
            maxUse = roomsUsedCount[r];
            resRoom = r;
        }
    }

    return resRoom;
}

int main(){
    // int n = 2;
    // vector<vector<int>> meetings = {{0,10},{1,5},{2,7},{3,4}};

    int n = 3;
    vector<vector<int>> meetings = {{1,20},{2,10},{3,5},{4,9},{6,8}};
    cout<<mostBooked(n, meetings);
    return 0;
}