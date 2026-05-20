
// Problem link - https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/?envType=daily-question&envId=2026-05-20

#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach O(n^3)
vector<int> findThePrefixCommonArray1(vector<int>& A, vector<int>& B) {
    int n = A.size();

    // keep track of resultant array in `res`
    vector<int> res(n, 0);

    // step 1 - iterate on each element of input array
    int count;
    for(int i=0; i<n; i++){
        count = 0;
        // step 2 - iterate till ith index 
        for(int ai=0; ai<=i; ai++){
            for(int bi=0; bi<=i; bi++){
                // step 3 - check if B's element is present in A's array
                if(B[bi] == A[ai]){
                    // increment count
                    count++;
                    break;
                }
            }
        }

        // step 4 - store count into result, `res`
        res[i] = count;
    }

    // step 5 - return final result, `res`
    return res;
}

// Better Approach O(n^2)
vector<int> findThePrefixCommonArray2(vector<int>& A, vector<int>& B) {
    int n = A.size();

    // initialize presence trackers for values seen so far in A and B prefixes
    // Use size n+1 because values are in the range [1, n].
    vector<bool> isPresentA(n+1, false), isPresentB(n+1, false);

    // result array to store prefix common counts for each index i
    vector<int> res(n, 0);

    // step 1 - iterate over each prefix ending at index i
    int count = 0;
    for(int i = 0; i < n; i++){
        // mark current elements as seen in their respective prefixes
        isPresentA[A[i]] = true;
        isPresentB[B[i]] = true;

        // step 2 - count numbers that have appeared in both prefixes [0..i]
        count = 0;
        for(int k = 1; k <= n; k++){
            if(isPresentA[k] && isPresentB[k]){
                count++;
            }
        }

        // step 3 - store the count for prefix ending at index i
        res[i] = count;
    }

    // step 4 - return final result, `res`
    return res;
}


// Optimal Approach `O(n)`
vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int n = A.size();

    // keep track of frequency of each element from A & B
    vector<int> frq(n+1, 0);

    // store final result in `res`
    vector<int> res(n, 0);

    // keep track of count
    int count = 0;
    
    // step 1 - iterate over each index i representing prefix [0..i]
    for(int i=0; i<n; i++){
        // include A[i] into frequency map
        frq[A[i]]++;

        // step 2 - check if a value's frequency becomes 2 after adding from A,
        if(frq[A[i]] == 2){
            count += 1;
        }

        // step 3 - include B[i] into frequency map (for B's prefix)
        frq[B[i]]++;

        // step 4 - similarly, if frequency becomes 2 after adding from B,
        if(frq[B[i]] == 2){
            count += 1;
        }

        // step 5 - store the current number of common elements for prefix [0..i]
        res[i] = count;
    }

    // step 6 - return final result, `res`
    return res;
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
    vector<int> A = {1,3,2,4}, B = {3,1,2,4};

    // vector<int> A = {2,3,1}, B = {3,1,2};
    vector<int> res = findThePrefixCommonArray(A, B);
    printVector(res);
    return 0;
}