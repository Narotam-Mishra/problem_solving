
#include<bits/stdc++.h>
using namespace std;

// utility function to add 1 to binary
void addOne(string& s) {
    int i = s.length() - 1;

    while (i >= 0 && s[i] != '0') {
        s[i] = '0';
        i--;
    }
    if (i < 0) {
        s = '1' + s;
    }
    else {
        s[i] = '1';
    }
}

int numSteps(string s) {
    // keep track of number of steps
    int steps = 0;

    // step 1 - iterate on each binary number
    while (s.length() > 1) {
        int n = s.length();
        // step 2 - for even number remove LSB
        if (s[n - 1] == '0') {
            s.pop_back();
        }

        // step 3 - for odd number add 1 to it
        else {
            addOne(s);
        }

        // step 4 - increment step for each operation
        steps++;
    }

    // step 5 - return number of steps
    return steps;
}

int main() {
    // string s = "1101";

    // string s = "10";

    string s = "1";
    cout << numSteps(s);
    return 0;
}