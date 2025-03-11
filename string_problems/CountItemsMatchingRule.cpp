
#include<bits/stdc++.h>
using namespace std;

int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
    // step 1 - map ruleKey to corresponding index
    int index;
    if(ruleKey == "type"){
        index = 0;
    }else if(ruleKey == "color"){
        index = 1;
    }else{
        index = 2;
    }

    // step 2 - initialize a counter to count the matching items
    int count = 0;

    // step 3 - traverse list items 
    for(int i=0; i<items.size(); i++){
        // step 4 - check if the value at the corresponding index matches the ruleValue
        if(items[i][index] == ruleValue){
            count++;
        }
    }

    // step 5 - return count of matching items
    return count;
}

int main(){
    vector<vector<string>> items = {
        {"phone", "blue", "pixel"},
        {"computer", "silver", "lenovo"},
        {"phone", "gold", "iphone"}
    };
    string ruleKey = "type", ruleValue = "phone";
    cout<<countMatches(items, ruleKey, ruleValue)<<endl;
    return 0;
}