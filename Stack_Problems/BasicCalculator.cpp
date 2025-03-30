
#include<bits/stdc++.h>
using namespace std;

int calculate(string s) {
    // step 1 - use stack to evalute the expression
    stack<int> st;

    // step 2 - intialize all necessary variables
    int sign = 1;
    int res = 0;
    int num = 0;

    // step 3 - iterate on each character of input string `s` and evaluate expression
    for (char ch : s) {
        // if current character is number then format it
        if (ch >= '0' && ch <= '9') {
            num = (num * 10) + (ch - '0');
        } else if (ch == '+') {
            // evalutate the expression from left for '+'
            res += sign * num;

            // save recent sign
            sign = 1;

            // reset the number `num`
            num = 0;
        } else if (ch == '-') {
            // evalutate the expression from left for '+'
            res += sign * num;

            // save recent sign
            sign = -1;

            // reset the number `num`
            num = 0;
        } else if (ch == '(') {
            // push result `res` and `sign` onto stack for `(`
            st.push(res);
            st.push(sign);

            // reset sign and result `res` for new expression
            res = 0;
            sign = 1;
        } else if (ch == ')') {
            // evaluate current expression
            res += sign * num;

            // `)` marks end of expression so pop from stack for sign of expression
            res *= st.top(); st.pop();

            // add result for expression
            res += st.top();  st.pop();

            // reset number `num`
            num = 0;
        }
    }

    // step 4 - add and return last number to result `res`
    return res + (sign * num);
}

int main(){
    // string s = "1 + 1";

    // string s = " 2-1 + 2 ";

    string s = "(1+(4+5+2)-3)+(6+8)";
    cout<<calculate(s)<<endl;
    return 0;
}