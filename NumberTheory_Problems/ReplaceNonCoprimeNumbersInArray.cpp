
// Problem link - https://leetcode.com/problems/replace-non-coprime-numbers-in-array/?envType=daily-question&envId=2025-09-16

#include<bits/stdc++.h>
using namespace std;

// utility function to find GCD of two numbers
int findGCD(int a, int b){
    while(b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// utility function to find LCM of two numbers
long long findLCM(int a, int b){
    return ((long long) a * b) / findGCD(a, b);
}

vector<int> replaceNonCoprimes1(vector<int>& nums) {
    // step 1 - create copy of input array `nums` in `res`
    vector<int> res = nums;
    
    // pointer to keep track of current position in res
    int i = 0;

    // step 2 - process the array until no more adjacent non-coprime pairs exist
    while(i < res.size() - 1){
        if(findGCD(res[i], res[i+1]) > 1){
            // step 3 - calculate LCM of the two adjacent numbers
            long long lcmValue = findLCM(res[i], res[i+1]);

            // step 4 - remove the two numbers and replace with their LCM
            res.erase(res.begin() + i, res.begin() + i + 2);
            res.insert(res.begin() + i, (int)lcmValue);

            // step 5 - move back one position to check if new LCM
            // creates a non-coprime pair with the previous element
            if(i > 0){
                i--;
            }
        }else{
            // otherwise, move to next position if current pair is co-prime
            i++;
        }
    }

    // step 6 - return final result `res`
    return res;
}

vector<int> replaceNonCoprimes2(vector<int>& nums) {
    // store final result in `res`
    vector<int> res;
    
    // step 1 - process the array until no more adjacent non-coprime pairs exist
    for(int num : nums){
        // step 2 - keep merging the current number with the last element in result
        // as long as they are non-coprime
        while(!res.empty() && findGCD(res.back(), num) > 1){
            // step 3 - replace num with LCM of last element and current num
            num = findLCM(res.back(), num);
            
            // step 4 - remove the last element
            res.pop_back();
        }

        // step 5 - add the (possibly merged) number to result `res`
        res.push_back(num);
    }

    // step 6 - return final result `res`
    return res;
}

vector<int> replaceNonCoprimes(vector<int>& nums) {
    // store final result in `res` 
    vector<int> res;

    // step 1 - process the array until no more adjacent non-coprime pairs exist
    for(int num : nums){
        // step 2 - keep merging the current number with the last element in result
        while(!res.empty()){
            int prevNum = res.back();
            int currNum = num;

            // as long as they are non-coprime
            int gcdValue = gcd(prevNum, currNum);
            if(gcdValue == 1){
                break;
            }

            int lcmValue = prevNum / gcdValue * currNum;

            // step 3 - replace num with LCM of last element and current num
            num = lcmValue;

            // step 4 - remove the last element
            res.pop_back();
        }

        // step 5 - add the (possibly merged) number to result `res`
        res.push_back(num);
    }

    // step 6 - return final result `res`
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
    // vector<int> nums = {6,4,3,2,7,6,2};

    vector<int> nums = {2,2,1,1,3,3,3};
    vector<int> res = replaceNonCoprimes(nums);
    printVector(res);
    return 0;
}