
#include<bits/stdc++.h>
using namespace std;

bool isSortedArray(vector<int>& arr){
    for(int i=1; i<arr.size(); i++){
        if(arr[i-1] > arr[i]) return false;
    }
    return true;
}

void bogoSort(vector<int>& arr){
    // Seed for random number generation
    srand(time(0));
    while (!isSortedArray(arr)){
        // Shuffle the array
        for(int i=arr.size()-1; i>0; i--){
            // This ensures that the generated random index j will be within the bounds of the array from 0 to i.
            int j = rand() % (i+1);
            swap(arr[i], arr[j]);
        }
    }
}

int main(){
    vector<int> arr = {5, 2, 9, 1, 6};
    cout<<"Unsorted Array: ";
    for(int num: arr){
        cout<<num<<" ";
    }
    cout<<endl;

    bogoSort(arr);
    cout<<"Sorted Array: ";
    for(int num: arr){
        cout<<num<<" ";
    }
    return 0;
}