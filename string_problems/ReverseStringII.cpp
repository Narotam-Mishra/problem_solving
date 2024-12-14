
// Problem link : https://leetcode.com/problems/reverse-string-ii/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

#include<bits/stdc++.h>
using namespace std;

string reverseStr(string s, int k) {
    int n = s.size();

    // step 1 - traverse the string in steps of 2k
    for (int i = 0; i < n; i += 2 * k) {
        // step 2 - reverse the first k characters within the current 2k block
        int left = i;

        // ensure the right pointer doesn't exceed the string length
        int right = min(i + k - 1, n - 1);

        // step 3 - reverse the segment using a two-pointer approach
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }

    // step 4 - convert the array back to a string and return the result
    return s;
}

int main(){
    // string str = "abcdefg";
    // int k = 2;

    string str = "abcd";
    int k = 2;
    cout<<reverseStr(str, k)<<endl;
    return 0;
}