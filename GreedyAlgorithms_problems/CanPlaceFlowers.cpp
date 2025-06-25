
// Problem link - https://leetcode.com/problems/can-place-flowers/description/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    // track down number of flowers planted
    int planted = 0;
    int len = flowerbed.size();

    // step 1 - iterate on each flowerbed
    for (int i = 0; i < len; i++) {
        // step 2 - check if current flowerbed is empty (0)
        if (flowerbed[i] == 0) {
            // check left neighbour of flowebed is empty or not
            bool leftNeighbourEmpty = (i == 0) || (flowerbed[i - 1] == 0);

            // check right neighbour of flowebed is empty or not
            bool rightNeighbourEmpty = (i == len - 1) || (flowerbed[i + 1] == 0);

            // step 3 - if both neighbors are safe(empty), we can plant here
            if (leftNeighbourEmpty && rightNeighbourEmpty) {
                // plant flower
                flowerbed[i] = 1;

                // count planted flower
                planted++;

                // step 4 - early termination if we have planted enough flowers
                if (planted >= n) {
                    return true;
                }
            }
        }
    }

    // step 5 - check and return if we planted at least 'n' flowers
    return planted >= n;
}

int main(){
    // vector<int> flowerbed = {1,0,0,0,1};
    // int n = 1;

    vector<int> flowerbed = {1,0,0,0,1};
    int n = 2;
    bool res = canPlaceFlowers(flowerbed, n);
    res ? cout<<"true" : cout<<"false";
    return 0;
}