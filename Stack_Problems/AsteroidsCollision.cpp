
// Problem link - https://leetcode.com/problems/asteroid-collision/

#include<bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;
    for(int ast : asteroids){
        if(ast > 0 || st.empty()){
            // If the current asteroid is positive, or the stack is empty,
            // it will not collide with any previous asteroids, so we push it onto the stack.
            st.push(ast);
        }else{
            // If the current asteroid is negative
            while(!st.empty() && st.top() > 0 && st.top() < abs(ast)){
                // If the top of the stack is positive and has a smaller magnitude than the current asteroid
                // then the top of the stack will be destroyed, 
                // so we pop it and repeat the collision check with the new top
                st.pop();
            }
            if(st.empty() || st.top() < 0){
                // If the stack is empty or the top of the stack is negative, 
                // then the current asteroid will not collide with any other asteroids, 
                // So, we push the current asteroid onto the stack.
                st.push(ast);
            }else if(!st.empty() && st.top() == abs(ast)){
                // If the top of the stack has the same magnitude as the current asteroid, 
                // both asteroids will explode & hence we pop from stack
                st.pop();
            }
        }
    }

    // store stack items to an array
    vector<int> res(st.size());
    int i = res.size() - 1;
    while (!st.empty()){
        res[i--] = st.top();
        st.pop();
    }
    return res;
}

int main(){
    // vector<int> ast = {-5, -2, 4, 3, 1, -6, 8, -2};

    // vector<int> ast = {5, 10, -5};

    vector<int> ast = {-2, -1, 1, 2};

    vector<int> res = asteroidCollision(ast);
    for(int ans : res){
        cout<<ans<<" ";
    }
    cout<<endl;
    return 0;
}