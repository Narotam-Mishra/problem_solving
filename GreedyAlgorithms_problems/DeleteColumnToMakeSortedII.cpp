
// Problem link - https://leetcode.com/problems/delete-columns-to-make-sorted-ii/description/?envType=daily-question&envId=2025-12-21

#include<bits/stdc++.h>
using namespace std;

int minDeletionSize(vector<string>& strs) {
    // get row and column size of string array
    int r = strs.size();
    int c = strs[0].size();
    
    // keep track of already sorted column to avoid unnecessary deletion
    vector<bool> alreadySorted(r, false);

    // step 1 - process columns left to right
    int deletionCount = 0;
    for(int col=0; col<c; col++){
        bool deleted = false;

        // step 2 - check if current column violates order
        for(int row=0; row<r-1; row++){
            if(!alreadySorted[row] && strs[row][col] > strs[row+1][col]){
                // must delete this column
                deletionCount++;
                deleted = true;
                break;
            }
        }

        // skip marking sorted pair if column was already deleted
        if(deleted) continue;

        // step 3 - update which pairs are now confirmed sorted
        for(int i=0; i<r-1; i++){
            alreadySorted[i] = alreadySorted[i] | (strs[i][col] < strs[i+1][col]);
        }
    }

    // step 4 - return minimum deletion count
    return deletionCount;
}

int main(){
    // vector<string> strs = {"ca","bb","ac"};

    // vector<string> strs = {"xc","yb","za"};

    vector<string> strs = {"zyx","wvu","tsr"};
    cout<<minDeletionSize(strs);
    return 0;
}