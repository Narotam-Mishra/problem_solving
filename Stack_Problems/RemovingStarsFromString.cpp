
// Problem link - https://leetcode.com/problems/removing-stars-from-a-string/description/

#include<bits/stdc++.h>
using namespace std;

string removeStars(string s) {
    stack<char> st;
    for(int i=0; i<s.size(); i++){
        if(s[i] != '*'){
            st.push(s[i]);
        }else{
            if(!st.empty()){
                st.pop();
            }
        }
    }

    stringstream res;
    while(!st.empty()){
        res << st.top();
        st.pop();
    }
    string ans = res.str();
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    string str = "leet**cod*e";
    cout<<removeStars(str)<<endl;
    return 0;
}