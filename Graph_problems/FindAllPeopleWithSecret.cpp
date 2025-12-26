
// Problem link - https://leetcode.com/problems/find-all-people-with-secret/

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
    // step 1 - mark true for person who initially knows secret
    vector<bool> knowSecret(n, false);
    knowSecret[0] = true;
    knowSecret[firstPerson] = true;

    // step 2 - create time to meetings map (ordered map)
    // where time should be sorted in ascending order
    map<int, vector<P>> timeMeetingsMap;
    for(vector<int>& meeting : meetings){
        int person1 = meeting[0];
        int person2 = meeting[1];
        int time = meeting[2];

        // populate time-meetings map
        timeMeetingsMap[time].push_back({person1, person2});
    }

    // step 3 - traverse in time-meeting map
    for(auto &it : timeMeetingsMap){
        // extract time and meeting
        int time = it.first;
        vector<P> meets = it.second;

        // step 4 - make graph using adjaceny list
        unordered_map<int, vector<int>> adjList;
        queue<int> qu;
        unordered_set<int> visited;
        for(auto& [p1, p2] : meets){
            adjList[p1].push_back(p2);
            adjList[p2].push_back(p1);

            // add person1 to queue and set
            if(knowSecret[p1] == true && visited.find(p1) == visited.end()){
                qu.push(p1);
                visited.insert(p1);
            }

            // add person2 to queue and set
            if(knowSecret[p2] == true && visited.find(p2) == visited.end()){
                qu.push(p2);
                visited.insert(p2);
            }
        }

        // step 5 - spread secret by performing BFS traversal on graph
        while (!qu.empty()){
            int person = qu.front();
            qu.pop();

            for(auto &nextperson : adjList[person]){
                if(knowSecret[nextperson] == false){
                    knowSecret[nextperson] = true;
                    qu.push(nextperson);
                }
            }
        }
    }

    // step 6 - form result, `res` and return it
    vector<int> res;
    for(int i=0; i<n; i++){
        if(knowSecret[i]){
            res.push_back(i);
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
    // int n = 6;
    // vector<vector<int>> meetings = {{1,2,5},{2,3,8},{1,5,10}};
    // int firstPerson = 1;

    // int n = 4;
    // vector<vector<int>> meetings = {{3,1,3},{1,2,2},{0,3,3}};
    // int firstPerson = 3;

    int n = 5;
    vector<vector<int>> meetings = {{3,4,2},{1,2,1},{2,3,1}};
    int firstPerson = 1;
    vector<int> res = findAllPeople(n, meetings, firstPerson);
    printVector(res);
    return 0;
}