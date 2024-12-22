
#include<bits/stdc++.h>
using namespace std;

int maxNumberOfBalloons(string text) {
    // step 1 - initialize a frequency array for 26 letters of the alphabet
    vector<int> freq(26, 0);

    // step 2 - populate the frequency array based on the characters in the text
    for(char ch : text){
        freq[ch - 'a']++;
    }

    // step 3 - compute the maximum number of "balloon" instances
    int bCount = freq['b' - 'a'] ;
    int aCount = freq['a' - 'a'];
    int lCount = freq['l' - 'a'] / 2 ;
    int oCount = freq['o' - 'a'] / 2;
    int nCount = freq['n' - 'a'];

    // step 4 - return the minimum count among all required characters
    return min({bCount, aCount, lCount, oCount, nCount});
}

int main(){
    string text = "nlaebolko";
    cout<<maxNumberOfBalloons(text)<<endl;
    return 0;
}