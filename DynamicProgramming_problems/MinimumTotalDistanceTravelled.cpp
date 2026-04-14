
// Problem link - https://leetcode.com/problems/minimum-total-distance-traveled/description/?envType=daily-question&envId=2026-04-14

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solveRec(int ri, int fj, vector<int>& robot, vector<int>& positions, vector<vector<ll>>& memo){
    // base case
    // no more distance to be covered
    if(ri >= robot.size()) return 0;
    if(fj >= positions.size()) return 1e12;

    // if answer is already computed, then return
    if(memo[ri][fj] != -1){
        return memo[ri][fj];
    }

    // recursive case: take current factory and skip current factory
    ll take_curr_factory = abs(robot[ri] - positions[fj]) + solveRec(ri+1, fj+1, robot, positions, memo);
    ll skip_curr_factory = solveRec(ri, fj+1, robot, positions, memo);

    // return minimum total distance travelled
    return memo[ri][fj] = min(take_curr_factory, skip_curr_factory);
}

ll minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
    // step 1 - sort factory and robot for efficiency
    sort(robot.begin(), robot.end());
    sort(begin(factory), end(factory));

    // step 2 - expand factory to maintain limit
    vector<int> positions;
    for(int i=0; i<factory.size(); i++){
        int limit = factory[i][1];
        int pos = factory[i][0];

        for(int j=0; j<limit; j++){
            positions.push_back(pos);
        }
    }

    // memoization table
    int m = robot.size();
    int n = positions.size();
    vector<vector<ll>> memo(m+1, vector<ll>(n+1, -1));

    // step 3 - solve recursilvely and return
    return solveRec(0, 0, robot, positions, memo);
}

int main(){
    vector<int> robot = {0,4,6};
    vector<vector<int>> factory = {{2,2},{6,2}};

    // vector<int> robot = {1,-1};
    // vector<vector<int>> factory = {{-2,1},{2,1}};
    cout<<minimumTotalDistance(robot, factory);
    return 0;
}