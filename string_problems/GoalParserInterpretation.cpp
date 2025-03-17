
#include<bits/stdc++.h>
using namespace std;

string interpret(string command) {
    // step 1 - initialize an empty string `res` to store the result
    string res = "";
    int i = 0;

    // step 2 - iterate on input string `command` and scane each character
    while (i < command.size()) {
        // 'G' remains unchanged
        if (command[i] == 'G') {
            res += "G";
            i++;
        } else if (command[i] == '(') {
            // check if it's "()" or "(al)"
            if (command[i + 1] == ')') {
                // "()" will be interprreted as 'o'
                res += "o";
                i += 2;
            } else {
                // "(al)" is interpreted as "al"
                res += "al";
                i += 4;
            }
        }
    }

    // step 3 - return result string `res`
    return res;
}

int main(){
    // string command = "G()(al)";

    // string command = "G()()()()(al)";

    string command = "(al)G(al)()()G";
    cout<<interpret(command)<<endl;
    return 0;
}