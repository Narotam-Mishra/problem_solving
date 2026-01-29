
// Problem link - https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/?envType=daily-question&envId=2026-01-29

#include<bits/stdc++.h>
using namespace std;

void applyFloydWarshall(vector<vector<long long>>& adjMatrix, vector<char>& original, vector<char>& changed, vector<int>& cost){
    // populate adjacency matrix with cost
    for(int i=0; i<original.size(); i++){
        int src = original[i] - 'a';
        int tar = changed[i] - 'a';

        adjMatrix[src][tar] = min(adjMatrix[src][tar], (long long)cost[i]);
    }

    // apply Floyd Warshall Algorithm
    for(int k=0; k<26; k++){
        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++){
                adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
            }
        }
    }
}

long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
    // step 1 - create adjacency matrix and populate its cost
    vector<vector<long long>> adjMatrix(26, vector<long long>(26, INT_MAX));

    // step 2 - apply Floyd Warshall Algorithm
    applyFloydWarshall(adjMatrix, original, changed, cost);

    // step 3 - calculate minimum cost
    long long ans = 0;
    for(int i=0; i<source.length(); i++){
        // skip same character
        if(source[i] == target[i]){
            continue;
        }

        // check if no path exist
        if(adjMatrix[source[i] - 'a'][target[i] - 'a'] == INT_MAX){
            // return -1 immediately
            return -1;
        }

        ans += adjMatrix[source[i] - 'a'][target[i] - 'a'];
    }

    // step 4 - return minimum cost from `ans`
    return ans;
}

int main(){
    // string source = "abcd", target = "acbe";
    // vector<char> original = {'a','b','c','c','e','d'}, changed = {'b','c','b','e','b','e'};
    // vector<int> cost = {2,5,5,1,2,20};

    // string source = "aaaa", target = "bbbb";
    // vector<char> original = {'a','c'}, changed = {'c','b'};
    // vector<int> cost = {1,2};

    string source = "abcd", target = "abce";
    vector<char> original = {'a'}, changed = {'e'};
    vector<int> cost = {10000};
    cout<<minimumCost(source, target, original, changed, cost);
    return 0;
}