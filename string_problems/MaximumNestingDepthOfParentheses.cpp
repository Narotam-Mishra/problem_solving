
#include<bits/stdc++.h>
using namespace std;

int maxDepth(string s) {
    // step 1 - track current depth and maximu depth in `depth` & `maxiDepth` 
    int depth = 0, maxiDepth = 0;

    // step 2 - iterate on string `s`
    for (char ch : s) {
        if (ch == '(') {
            // step 3 - increase depth for every opening parenthesis
            depth++;

            // step 4 - find maximum depth `maxiDepth`
            maxiDepth = max(maxiDepth, depth);
        }
        else if (ch == ')') {
            // step 5 - decrease depth for every closing parenthesis
            depth--;
        }
    }

    // step 6 - return max depth
    return maxiDepth;
}

int main(){
    // string s = "(1+(2*3)+((8)/4))+1";

    // string s = "(1)+((2))+(((3)))";

    string s = "()(())((()()))";
    cout<<maxDepth(s)<<endl;
    return 0;
}