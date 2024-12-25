
#include<bits/stdc++.h>
using namespace std;

int percentageLetter(string s, char letter) {
    // step 1: initialize a counter for the occurrences of the letter
    int len = s.length(), letterCount = 0;

    // step 2: iterate over each character in the string
    for (char ch : s) {
        if (ch == letter) {
            letterCount++;
        }
    }

    // step 3: calculate the percentage of the letter in the string
    int percentage = (letterCount * 100) / len;

    // step 4: return the percentage (no need to round down as integer division does it)
    return percentage;
}

int main(){
    // string s = "foobar"; 
    // char letter = 'o';

    string s = "jjjj"; 
    char letter = 'k';
    cout<<percentageLetter(s, letter)<<endl;
    return 0;
}