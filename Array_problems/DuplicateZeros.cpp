
// Problem link - https://leetcode.com/problems/duplicate-zeros/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

void duplicateZeros(vector<int>& arr) {
    int n = arr.size();

    // step 1 - count zeros in `arr` array
    int countZeros = 0;
    for(int num : arr){
        if (num == 0) countZeros++;
    }

    // step 2 - work backwards from the end to avoid overwriting unprocessed elements
    int i = n - 1;
    int writePosition = n + countZeros - 1;

    // step 3 - process element from right to left
    while(i >= 0){
        // step 4 - if write position is within the bound of original array
        if(writePosition < n){
            // place non-zero elements
            arr[writePosition] = arr[i];
        }

        // step 5 - if current element is zero, we need to duplicate it
        if(arr[i] == 0){
            // move write position to left for the duplicate
            writePosition--;

            // duplicate zero only if within bound
            if(writePosition < n){
                arr[writePosition] = 0;
            }
        }

        // step 6 - move both pointers
        i--;
        writePosition--;
    }
}

void printVector(vector<int>& vec){
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout<<vec[i];
        if (i < vec.size() - 1) {
            cout<<",";
        }
    }
    cout<< "]" <<endl;
}

int main(){
    // vector<int> arr = {1,0,2,3,0,4,5,0};

    vector<int> arr = {1,2,3};
    duplicateZeros(arr);

    printVector(arr);
    return 0;
}