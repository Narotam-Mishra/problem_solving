
// Problem link - https://www.codingninjas.com/studio/problems/occurrence-of-x-in-a-sorted-array_630456

#include<bits/stdc++.h>
using namespace std;

int findLeftIndex(vector<int> &arr, int x){
    int s = 0, e = arr.size() - 1;
    int leftIndex = -1;

    while (s <= e){
        int mid = (s + e) / 2;
        if (arr[mid] >= x){
            if (arr[mid] == x){
                leftIndex = mid;
            }
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return leftIndex;
}

int findRightIndex(vector<int> &arr, int x){
    int s = 0, e = arr.size() - 1;
    int righttIndex = -1;

    while (s <= e){
        int mid = (s + e) / 2;
        if (arr[mid] <= x){
            if (arr[mid] == x){
                righttIndex = mid;
            }
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    return righttIndex;
}

int count(vector<int>& arr, int n, int x) {
	int leftIndex = findLeftIndex(arr, x);
    int rightIndex = findRightIndex(arr, x);

    if(leftIndex != -1 && rightIndex != -1){
        return (rightIndex - leftIndex + 1);
    }
    return 0;
}
