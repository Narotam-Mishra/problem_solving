
// Problem link : https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/description/?envType=problem-list-v2&envId=bit-manipulation

#include<bits/stdc++.h>
using namespace std;

int countSetBits(int num){
    int setBits = 0;
    while(num > 0){
        setBits += num & 1;
        num = num >> 1;
    }
    return setBits;
}

// using custom comparator
bool customCompare(int a, int b){
    int countA = countSetBits(a);
    int countB = countSetBits(b);

    // sort by value when the number of bits is the same
    if(countA == countB){
        return a < b;
    }else{
        // otherwise sort by the number of set bits
        return countA < countB;
    }
}

vector<int> sortByBits(vector<int>& arr) {
    // sorting array using custom comparator
    sort(arr.begin(), arr.end(), customCompare);
    return arr;
}

int main(){
    vector<int> arr = {0,1,2,3,4,5,6,7,8};
    vector<int> res = sortByBits(arr);
    for(int num : res){
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}