
// Problem link - https://leetcode.com/problems/relative-ranks/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

vector<string> findRelativeRanks(vector<int>& score) {
    int n = score.size();

    // step 1 - create score to original index mapping
    vector<pair<int, int>> scoreWithIndex;
    for(int i=0; i<n; i++){
        scoreWithIndex.push_back({score[i], i});
    }

    // step 2 - sort in descending order of score
    sort(scoreWithIndex.begin(), scoreWithIndex.end(), [](const pair<int, int>& a, const pair<int, int>& b){
        // sort in descending order of score
        return a.first > b.first;
    });

    // step 3 - create mapping from score to rank
    unordered_map<int, string> scoreToRank;
    
    // step 4 - iterate on each score to assign its rank
    for(int i=0; i<scoreWithIndex.size(); i++){
        // step 5 - extract score from scoreWithIndex pairs
        int currentScore = scoreWithIndex[i].first;
        // rank is based on 1-based indexing
        int rank = i + 1;

        // step 6 - convert rank to appropriate string value
        string rankString = "";
        if(rank == 1){
            rankString = "Gold Medal";
        }else if(rank == 2){
            rankString = "Silver Medal";
        }else if(rank == 3){
            rankString = "Bronze Medal";
        }else{
            rankString = to_string(rank);
        }

        scoreToRank[currentScore] = rankString;
    }

    // step 7 - build result array using original order
    vector<string> res;
    for(int i=0; i<n; i++){
        res.push_back(scoreToRank[score[i]]);
    }

    // step 8 - return resultant array `res`
    return res;
}

void printVector(vector<string>& vec){
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
    // vector<int> score = {5,4,3,2,1};

    vector<int> score = {10,3,8,9,4};
    vector<string> res = findRelativeRanks(score);
    printVector(res);
    return 0;
}