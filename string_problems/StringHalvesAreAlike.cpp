
#include<bits/stdc++.h>
using namespace std;

// heper function to check if a character is vowel or not
bool isVowel(char ch){
    return string("aeiou").find(ch) != string::npos;
}
bool halvesAreAlike1(string s) {
    // initialize counters for vowels in the first and second halves
    int fvc = 0, svc = 0;
    int n = s.length();

    // iterate over both halves of the string
    for(int i = 0, j = n / 2; i < n / 2 && j < n; i++, j++){
        // check for vowels and increment the respective counter
        if(isVowel(tolower(s[i]))) fvc++;
        if(isVowel(tolower(s[j]))) svc++;
    }

    // check if the count of vowels in the first and second halves are equal
    return fvc == svc;
}

bool halvesAreAlike(string s) {
    // initialize counters for vowels in the first and second halves
    int fvc = 0, svc = 0;
    int n = s.length();

    // iterate over the input string `s`
    for (int i = 0; i < n; i++) {
        if (i < n / 2) {
            if (tolower(s[i]) == 'a' || tolower(s[i]) == 'e' || tolower(s[i]) == 'i' || tolower(s[i]) == 'o' || tolower(s[i]) == 'u')
                fvc++;
        }
        else {
            if (tolower(s[i]) == 'a' || tolower(s[i]) == 'e' || tolower(s[i]) == 'i' || tolower(s[i]) == 'o' || tolower(s[i]) == 'u')
                svc++;
        }
    }

    // check if count of vowels in first and second half are equal or not
    return fvc == svc;
}

int main(){
    // string str = "book";

    string str = "textbook";
    bool res = halvesAreAlike(str);
    res ? cout<<"true" : cout<<"false"<<endl;
    return 0;
}