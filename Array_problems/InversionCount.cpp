
// Problem link - https://hack.codingblocks.com/app/practice/1/374/problem

#include<bits/stdc++.h>
using namespace std;

int mergeArrayInversionCount(int *arr, int s, int e){
    int mid = (int)(s+e)/2;
    int i = s, j = e, k = s;
    int ic = 0;

    int *res = new int[10000];

    // merge arrays
    while(i<=s && j<=e){
        if(arr[i] < arr[j]){
            res[k++] = arr[i++];
        }else{
            res[k++] = arr[j++];
            // count cross inversion
            ic += mid-i+1;
        }
    }

    // if right half of array is exhausted
    while(i <= mid){
        res[k++] = arr[i++];
    }

    // if left half of array is exhausted
    while(j <= e){
        res[k++] = arr[j++];
        // count cross inversion
        ic += mid-i+1;
    }

    // copy arrays to original array
    for(int id=s; id<=e; id++){
        arr[id] = res[id];
    }

    // return inversion count
    return ic;
}

int inversionCount(int *arr, int l, int r){
    // Base case:
    if(l>=r){
        return 0;
    }

    // Recusively count inversion in left and right half of array
    int mid = (int)(l+r)/2;
    int lc = inversionCount(arr, l, mid);
    int rc = inversionCount(arr, mid+1, r);
    // count cross inversion count in merged array
    int ac = mergeArrayInversionCount(arr, l, r);
    return (lc+rc+ac);
}

int main(){
    int tc;
    cin>>tc;

    while(tc > 0){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        cout<<inversionCount(arr,0,n-1)<<endl;
    }
    return 0;
}