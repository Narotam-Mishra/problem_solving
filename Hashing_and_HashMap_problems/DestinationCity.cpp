
#include<bits/stdc++.h>
using namespace std;

string destCity(vector<vector<string>>& paths) {
    // step 1 - collect all starting cities in `startingCities` set
    unordered_set<string> startingCities;
    for(const auto& path : paths){
        startingCities.insert(path[0]);
    }

    // step 2 - find destination city
    for(const auto& path : paths){
        string cityB = path[1];
        if(startingCities.find(cityB) == startingCities.end()){
            return cityB;
        }
    }

    // if no city is found (though guaranteed in this problem), return null
    return "";
}

int main(){
    // vector<vector<string>> paths = {
    //     {"London", "New York"},
    //     {"New York", "Lima"},
    //     {"Lima", "Sao Paulo"}
    // };

    vector<vector<string>> paths = {
        {"B", "C"},
        {"D", "B"},
        {"C", "A"}
    };
    string res = destCity(paths);
    cout<<res<<endl;
    return 0;
}