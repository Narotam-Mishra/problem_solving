
// Problem link : https://leetcode.com/problems/design-an-ordered-stream/description/?envType=problem-list-v2&envId=design

#include<bits/stdc++.h>
using namespace std;

class OrderedStream {
private:
    // vector to store values
    vector<string> stream;
    // pointer to the smallest unprocessed ID
    int ptr;

public:
    OrderedStream(int n) {
        // initialize the vector of size `n`
        stream = vector<string>(n, "");
        
        // start the pointer at the beginning
        ptr = 0;
    }
    
    vector<string> insert(int idKey, string value) {
        // convert idKey to zero-based index
        int index = idKey - 1;
        
        // store the value at the correct position
        stream[index] = value;

        // store result in `res` vector
        vector<string> res;
        
        // collect contiguous values starting from `ptr`
        while(ptr < stream.size() && !stream[ptr].empty()){
            // add the value to the result
            res.push_back(stream[ptr]);
            
            // move the pointer to the next unprocessed ID
            ptr++;
        }

        // return the collected chunk
        return res;
    }
};

int main(){
    OrderedStream os(5);
    vector<string> res;

    res = os.insert(3, "cc");
    for (const auto& val : res) cout << val << " "; // Output: (empty)
    cout << endl;

    res = os.insert(1, "aa");
    for (const auto& val : res) cout << val << " "; // Output: aa
    cout << endl;

    res = os.insert(2, "bb");
    for (const auto& val : res) cout << val << " "; // Output: bb cc
    cout << endl;

    res = os.insert(5, "ee");
    for (const auto& val : res) cout << val << " "; // Output: (empty)
    cout << endl;

    res = os.insert(4, "dd");
    for (const auto& val : res) cout << val << " "; // Output: dd ee
    cout << endl;

    return 0;
}