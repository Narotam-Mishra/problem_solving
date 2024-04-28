
#include<bits/stdc++.h>
using namespace std;

vector<string> buildArray(vector<int>& target, int n) {
    // Initialize a list to store operations
    vector<string> stack;
    // Initialize a variable to track the current integer in the stream
    int i = 1;

    // Iterate through each number in the target array
    for(int num : target){
        // While the current integer in the stream is less than the target number
        while(i < num){
            // Push the current integer to the stack
            stack.push_back("Push");
            // Pop the integer immediately after pushing
            stack.push_back("Pop");
            // Move to the next integer in the stream
            i++;
        }
        // Push the current integer to the stack
        stack.push_back("Push");
        // Move to the next integer in the stream
        i++;
    }
    // Return the stack operations
    return stack;
}

int main(){
    vector<int> target = {1,2,3};
    int n = 3;
    vector<string> ans = buildArray(target, n);
    for(string val : ans){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}