
// Problem link - https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
    // store final result in `res`
    vector<vector<int>> res;

    // find size of `nums1` & `nums2`
    int m = nums1.size(), n = nums2.size();

    // step 1 - two pointers to track position in `nums1` and `nums2`
    int i = 0, j = 0;

    // step 2 - iterate on both input arrays and perform the given operation
    while (i < m && j < n) {
        // extract id and value from both input arrays
        int id1 = nums1[i][0];
        int val1 = nums1[i][1];

        int id2 = nums2[j][0];
        int val2 = nums2[j][1];

        // step 3 - id1 from nums1 is smaller, so it doesn't exist in nums2
        if (id1 < id2) {
            res.push_back({ id1, val1 });
            i++;
        }

        // step 4 - id2 from nums2 is smaller, so it doesn't exist in nums2
        else if (id1 > id2) {
            res.push_back({ id2, val2 });
            j++;
        }

        // step 5 - both ids are equal so sum their respective values and add it to
        // `res`
        else {
            res.push_back({ id1, val1 + val2 });
            i++;
            j++;
        }
    }

    // step 6 - handle remaining values
    while (i < m) {
        res.push_back({ nums1[i][0], nums1[i][1] });
        i++;
    }

    while (j < n) {
        res.push_back({ nums2[j][0], nums2[j][1] });
        j++;
    }

    // step 7 - convert to array and return final result array `res`
    return res;
}

void print2DVector(vector<vector<int>>& matrix){
    cout << "[";
    for (size_t i = 0; i < matrix.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j];
            if (j < matrix[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < matrix.size() - 1) cout << ",";
    }
    cout << "]" << std::endl;
}

int main(){
    // vector<vector<int>> nums1 = {{1,2},{2,3},{4,5}}, nums2 = {{1,4},{3,2},{4,1}};

    vector<vector<int>> nums1 = {{2,4},{3,6},{5,5}}, nums2 = {{1,3},{4,3}};
    vector<vector<int>> res = mergeArrays(nums1, nums2);
    print2DVector(res);
    return 0;
}