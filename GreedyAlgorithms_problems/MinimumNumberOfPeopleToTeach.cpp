
// Problem link - https://leetcode.com/problems/minimum-number-of-people-to-teach/?envType=daily-question&envId=2025-09-10

#include<bits/stdc++.h>
using namespace std;

int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
    // `sadUsers` are users who can't communicate with at least one friend
    unordered_set<int> sadUsers;

    // step - 1 : identify all problematic friendships and collect sad users
    for(auto &friends : friendships){
        // convert this to 0-based indexing
        int u = friends[0] - 1;
        int v = friends[1] - 1;

        // step 2 - create a set of languages known by user `u`
        unordered_set<int> langSet(begin(languages[u]), end(languages[u]));

        // step 3 - check if users u and v can communicate (share any common language)
        bool canTalk = false;
        for(int lang : languages[v]){
            if(langSet.count(lang)){
                // found common language
                canTalk = true;
                break;
            }
        }

        // step 4 - if they can't talk then they are sad users
        if(!canTalk){
            sadUsers.insert(u);
            sadUsers.insert(v);
        }
    }

    // step 5 - find the language that is already known by most sad users
    // array to count how many sad users know each language
    vector<int> language(n+1, 0);
    int mostKnownLang = -1;

    // step 6 - count language knowledge among sad users only
    for(int user : sadUsers){
        for(int lang : languages[user]){
            language[lang]++;
            mostKnownLang = max(mostKnownLang, language[lang]);
        }
    }

    // step 7 - calculate minimum teachings needed and return
    // if we teach the most popular language among sad users,
    // we need to teach (total sad users - users who already know that language)
    return sadUsers.size() - mostKnownLang;
}

int main(){
    // int n = 2;
    // vector<vector<int>> languages = {{1},{2},{1,2}};
    // vector<vector<int>> friendships = {{1,2},{1,3},{2,3}};

    int n = 3;
    vector<vector<int>> languages = {{2},{1,3},{1,2}, {3}};
    vector<vector<int>> friendships = {{1,4},{1,2},{3,4},{2,3}};
    cout<<minimumTeachings(n, languages, friendships);
    return 0;
}