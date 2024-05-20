
// Problem link - https://hack.codingblocks.com/app/contests/5320/199/problem

#include<bits/stdc++.h>
using namespace std;

int binarySearch(int *arr, int e, int target){
    int s = 0;
    while(s <= e){
        int mid = (s + e)/2;

        if(target == arr[mid]){
            return mid;
        }else if(target > arr[mid]){
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {7,13,27,31,43,54,61};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 61;
    cout<< binarySearch(arr, size, target)<<endl;
    return 0;
}