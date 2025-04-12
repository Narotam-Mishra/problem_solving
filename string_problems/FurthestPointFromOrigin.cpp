
// Problem link - https://leetcode.com/problems/furthest-point-from-origin/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

int furthestDistanceFromOrigin(string moves) {
    // step 1 - initialize counters
    int left = 0, right = 0, dash = 0;

    // step 2 - traverse each character of moves
    for (char move : moves) {
        // step 3 - count left, right & dashed (-)
        if (move == 'L') {
            left++;
        } else if (move == 'R') {
            right++;
        } else {
            dash++;
        }
    }

    // step 4 - assign all dash to the left
    int op1 = abs((left + dash) - right);

    // step 5 - assign all dash to the right
    int op2 = abs((right + dash) - left);

    // step 6 - return maximum distance from origin
    return max(op1, op2);
}

int main(){
    // string moves = "L_RL__R";

    // string moves = "_R__LL_";

    string moves = "_______";
    cout<<furthestDistanceFromOrigin(moves)<<endl;
    return 0;
}