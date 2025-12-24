
// Problem link - https://leetcode.com/problems/apple-redistribution-into-boxes/?envType=daily-question&envId=2025-12-24

#include<bits/stdc++.h>
using namespace std;

int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
    // step 1 - sort capacity in ascending order
    sort(begin(capacity), end(capacity), greater<int>());

    // step 2 - find sum of all apples
    int applesSum = 0;
    for(int a : apple){
        applesSum += a;
    }

    // step 3 - start distributing apples starting from largest box
    // and maintain box count
    int boxCount = 0;
    int currentApples = 0;
    for(int cap : capacity) {
        currentApples += cap;
        boxCount++;
        if(currentApples >= applesSum) {
            return boxCount;
        }
    }

    // step 4 - return the minimum number of boxes
    return boxCount;
}

int main(){
    // vector<int> apple = {1,3,2};
    // vector<int> capacity = {4,3,1,5,2};

    vector<int> apple = {5,5,5};
    vector<int> capacity = {2,4,2,7};
    cout<<minimumBoxes(apple, capacity);
    return 0;
}