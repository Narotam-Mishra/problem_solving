
#include<bits/stdc++.h>
using namespace std;

// utility method to find digit sum
int getDigitSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num = num / 10;
    }
    return sum;
}

int countLargestGroup(int n) {
    // step 1 - use map to store the size of each digit sum group
    unordered_map<int, int> digitSumMap;

    // step 2 - group numbers by their digit sums
    for(int i = 1; i <= n; i++){
        int digitSum = getDigitSum(i);
        digitSumMap[digitSum]++;
    }

    // step 3 - find the largest group size
    int maxGroupSize = 0;
    for(const auto& pair : digitSumMap){
        maxGroupSize = max(maxGroupSize, pair.second);
    }

    // step 4 - count how many groups have the largest size
    int largestGroupCount = 0;
    for(const auto& pair : digitSumMap){
        if(maxGroupSize == pair.second){
            largestGroupCount++;
        }
    }

    // step 5 - return the largest group count
    return largestGroupCount;
}

int main(){
    // int num = 13;

    int num = 2;
    cout<<countLargestGroup(num)<<endl;
    return 0;
}