
// Problem link - https://leetcode.com/problems/minimum-moves-to-make-array-complementary/description/?envType=daily-question&envId=2026-05-13

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach (105 TCs passed out of 113)
int minMoves1(vector<int>& nums, int limit) {
    int n = nums.size();

    // keep track of final result in `res` 
    int res = INT_MAX;

    // keep track of minimum moves
    int moves;

    // step 1: Try every possible target sum.
    // minimum pair sum can be 1 + 1 = 2.
    // maximum pair sum can be limit + limit = 2 * limit.
    for(int sum=2; sum<=2*limit; sum++){
        // for each sum initial move to 0
        moves = 0;

        // step 2 - check only the first half of the array.
        // each nums[i] is paired with nums[n - 1 - i].
        for(int i=0; i<n/2; i++){
            int a = nums[i];
            int b = nums[n-1-i];

            // case 1 - pair already has the target sum, so 0 moves are needed.
            if(a + b == sum){
                continue;
            }

            // case 2 - check whether the target sum can be achieved in exactly 1 move.
            // if we change one number only:
            // - the smallest possible sum is min(a, b) + 1.
            // - the largest possible sum is max(a, b) + limit.
            int minVal = min(a,b) + 1;
            int maxVal = max(a,b) + limit;

            if(sum >= minVal && sum <= maxVal){
                // target sum is inside the one-move range.
                moves += 1;
            }else{
                // case 3 - target sum cannot be made with 0 or 1 move,
                // so both numbers in the pair must be changed.
                moves += 2;
            }
        }

        // step 3 - keep the best answer among all target sums.
        res = min(res, moves);
    }

    // step 4 - return final result, `res`
    return res;
}

int minMoves(vector<int>& nums, int limit) {
    int n = nums.size();

    // step 1 - using difference array technique (DAT).
    // dat[sum] will finally store the total moves needed
    // to make every mirror pair equal to this target sum.
    vector<int> dat(2*limit+2, 0);

    // step 2 - process every mirror pair.
    // pair nums[i] with nums[n - 1 - i].
    for(int i=0; i<n/2; i++){
        int a = nums[i];
        int b = nums[n-1-i];

        // for this pair, these are the target sums possible in exactly 1 move.
        // minimum one-move sum: change bigger/smaller pair value to 1.
        // maximum one-move sum: change bigger/smaller pair value to limit.
        int minVal = min(a,b) + 1;
        int maxVal = max(a,b) + limit;

        // step 3 - initially assume this pair needs 2 moves for every target sum.
        // valid target sums are from 2 to 2 * limit.
        dat[2] += 2;
        dat[2*limit+1] -= 2;

        // step 4 - for sums in [minVal, maxVal], this pair needs only 1 move.
        // since we already added 2 moves, subtract 1 from this range.
        dat[minVal] += (-1);
        dat[maxVal+1] -= (-1);

        // step 5 - for the exact current sum a + b, this pair needs 0 moves.
        // since this sum is already in the one-move range, subtract 1 more.
        dat[a+b] += (-1);
        dat[a+b+1] -= (-1);
    }

    // step 6 - keep track of the minimum total moves among all target sums.
    int res = INT_MAX;

    // step 7 - convert the difference array into actual move counts using prefix sum.
    for(int sum=2; sum<=2*limit; sum++){
        dat[sum] += dat[sum - 1];

        // update answer with the minimum moves needed for this target sum.
        res = min(res, dat[sum]);
    }

    // step 8 - return final minimum moves.
    return res;
}

int main() {
    vector<int> nums = {1,2,4,3};
    int limit = 4;

    // vector<int> nums = {1,2,2,1};
    // int limit = 2;

    // vector<int> nums = {1,2,1,2};
    // int limit = 2;
    cout << minMoves(nums, limit);
    return 0;
}
