
// Problem link - https://leetcode.com/problems/capitalize-the-title/description/?envType=problem-list-v2&envId=string

#include<bits/stdc++.h>
using namespace std;

string capitalizeTitle(string title) {
    // step 1 - split title by space using string stream
    string res;
    stringstream ss(title);
    string word;

    // step 2 - iterate on each word of title
    // and capitalize it as per given conditions
    while (ss >> word) {
        if (word.length() <= 2) {
            for (char& c : word) {
                c = tolower(c);
            }
        }
        else {
            word[0] = toupper(word[0]);
            for (int i = 1; i < word.length(); i++) {
                word[i] = tolower(word[i]);
            }
        }
        // step 3 - add space
        res += word + " ";
    }

    // remove the trailing space
    if (!res.empty()) {
        res.pop_back();
    }

    // step 4 - return `res`
    return res;
}

int main(){
    // string title = "capiTalIze tHe titLe";

    // string title = "First leTTeR of EACH Word";

    string title = "i lOve leetcode";
    cout<<capitalizeTitle(title)<<endl;
    return 0;
}