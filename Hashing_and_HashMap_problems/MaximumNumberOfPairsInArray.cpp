
#include<bits/stdc++.h>
using namespace std;

vector<int> numberOfPairs(vector<int>& nums) {
    // step 1 - create frequency array map to count frquency of each array elements
    vector<int> freqMapArr(101, 0);
    for (int num : nums) {
        freqMapArr[num]++;
    }

    // step 2 - calculate number of pairs and number of left over elements from frequency array map
    int numOfPairs = 0, numOfleftOvers = 0;
    for (int count : freqMapArr) {
        // count how many pairs can be formed
        numOfPairs += (int)count / 2;

        // count remaining unpaired numbers
        numOfleftOvers += count % 2;
    }

    // step 3 - return required result
    return vector<int>{numOfPairs, numOfleftOvers};
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
    // vector<int> nums = {1,3,2,1,3,2,2};

    // vector<int> nums = {1,1};

    vector<int> nums = {0};
    vector<int> res = numberOfPairs(nums);
    printVector(res);
    return 0;
}