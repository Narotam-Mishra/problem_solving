
#include<bits/stdc++.h>
using namespace std;

int sumOfUnique(vector<int>& nums) {
    // step 1 - intialize `sum` variable to store unique numbers sum
    int sum = 0;

    // step 2 - create frequency array to count frequency
    vector<int> frqArr(101, 0);

    // fill frequency
    for(int num : nums){
        frqArr[num]++;
    }

    // step 3 - iterate over frequency array and add unique numbers to sum
    for(int i=0; i<101; i++){
        if(frqArr[i] == 1){
            sum += i;
        }
    }

    // step 4 - return unique numbers sum
    return sum;
}

int main(){
    // vector<int> nums = {1,2,3,2};

    // vector<int> nums = {1,1,1,1,1};

    vector<int> nums = {1, 2, 3, 4, 5};
    cout<<sumOfUnique(nums)<<endl;
    return 0;
}