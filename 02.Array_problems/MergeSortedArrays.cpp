
#include<bits/stdc++.h>
using namespace std;

void mergeArr(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m-1, j=n-1, k=m+n-1;

    while (i>=0 && j>=0){
        // compare both array's number and store it
        if(nums1[i] > nums2[j]){
            nums1[k] = nums1[i];
            k--;
            i--;
        }else{
            nums1[k] = nums2[j];
            k--;
            j--;
        }
    }

    // if nums2[] is exhausted, simply copy paste remaining number from nums1[]  
    while(i>=0){
        nums1[k] = nums1[i];
        k--;
        i--;
    }

    // if nums1[] is exhausted, simply copy paste remaining number from nums2[]  
    while(j>=0){
        nums1[k] = nums2[j];
        k--;
        j--;
    }  
}
