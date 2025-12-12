
// Problem link - https://leetcode.com/problems/count-mentions-per-user/description/?envType=daily-question&envId=2025-12-12

#include<bits/stdc++.h>
using namespace std;

void performMessageEvent(vector<string>& event, vector<int>& mentionCount, vector<int>& offlineTime) {
    int timestamp = stoi(event[1]);
    vector<string> ids;
    stringstream ss(event[2]);

    // generate token 
    string token;
    while (ss >> token) {
        // by defualt it breaks token on the basis of whitespaces
        ids.push_back(token);
    }

    // process all IDs
    for (string id : ids) {
        if (id == "ALL") {
            for (int i = 0; i < mentionCount.size(); i++) {
                // mention all users
                mentionCount[i]++;
            }
        }
        else if (id == "HERE") {
            for (int i = 0; i < mentionCount.size(); i++) {
                // mention only online users
                if (offlineTime[i] == 0 || offlineTime[i] + 60 <= timestamp) {
                    mentionCount[i]++;
                }
            }
        }
        else {
            // fetch id values (i.e, x from idx) and increment it
            mentionCount[stoi(id.substr(2))]++;
        }
    }
}

vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
    vector<int> mentionCount(numberOfUsers);
    vector<int> offlineTime(numberOfUsers);

    auto comparator = [](vector<string>& ev1, vector<string>& ev2) {
        int t1 = stoi(ev1[1]);
        int t2 = stoi(ev2[1]);

        // check if timestamps are equal
        if (t1 == t2) {
            // then sort on the basis of message
            // Offline should come first in case of timestamp tie
            return ev1[0][1] > ev2[0][1];
        }
        return t1 < t2;
        };

    // step 1 - sort events on the basis of timestamps
    sort(events.begin(), events.end(), comparator);

    // step 2 - perform operation for each event
    for (vector<string> event : events) {
        if (event[0] == "MESSAGE") {
            performMessageEvent(event, mentionCount, offlineTime);
        }
        else if (event[0] == "OFFLINE") {
            int timestamp = stoi(event[1]);
            int id = stoi(event[2]);
            offlineTime[id] = timestamp;
        }
    }

    // step 3 - return final result, `mentionCount`
    return mentionCount;
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
    // int numberOfUsers = 2;
    // vector<vector<string>> events = {{"MESSAGE","10","id1 id0"},{"OFFLINE","11","0"},{"MESSAGE","71","HERE"}};

    // int numberOfUsers = 2;
    // vector<vector<string>> events = {{"MESSAGE","10","id1 id0"},{"OFFLINE","11","0"},{"MESSAGE","12","ALL"}};

    int numberOfUsers = 2;
    vector<vector<string>> events = {{"OFFLINE","10","0"},{"MESSAGE","12","HERE"}};
    vector<int> res = countMentions(numberOfUsers, events);
    printVector(res);
    return 0;
}