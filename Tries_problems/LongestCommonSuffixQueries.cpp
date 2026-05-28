
// Problem link - https://leetcode.com/problems/longest-common-suffix-queries/description/?envType=daily-question&envId=2026-05-28

#include<bits/stdc++.h>
using namespace std;

struct trieNode {
    int idx;
    trieNode* children[26];
    ~trieNode() {
        for (int i = 0; i < 26; i++) {
            delete children[i];
        }
    }
};

// utility function to returns a newly allocated trie node 
// initialized with given id and null children.
trieNode* getNode(int id){
    // allocate and initialize a new trie node.
    // `idx` stores the index of the shortest word 
    trieNode* temp = new trieNode();
    temp->idx = id;

    // Initialize all child pointers to nullptr for 26 lowercase letters.
    for(int i=0; i<26; i++){
        temp->children[i] = NULL;
    }

    return temp;
}

// utility function to insert into trie's node
void insertInTrie(trieNode* root, int i, vector<string>& wordsContainer){
    string word = wordsContainer[i];
    int n = word.length();

    // insert characters in reverse order to build a trie of suffixes.
    for(int j=n-1; j>=0; j--){
        char ch = word[j];
        int chIdx = ch - 'a';

        // create child node if it doesn't exist. Initialize its idx with current word index.
        if(root->children[chIdx] == NULL){
            root->children[chIdx] = getNode(i);
        }

        // move down the trie along the character edge.
        root = root->children[chIdx];

        // keep the index of the shortest word seen for this node. This helps
        // return the smallest-index word that has the longest matching suffix.
        if(wordsContainer[root->idx].length() > n){
            root->idx = i;
        }
    }
}

// utility function to search the trie using characters from the end of the query word.
int serachInTrie(trieNode* root, string& word){
    // start with the root's idx as default (empty suffix match).
    int res_idx = root->idx;
    int n = word.length();

    // walk down the trie following the reversed query. If at any point there is no
    // matching child, return the best index found so far.
    for(int i=n-1; i>=0; i--){
        int ch_idx = word[i] - 'a';

        root = root->children[ch_idx];
        if(root == NULL){
            return res_idx;
        }

        // update result index to the stored index at this node.
        res_idx = root->idx;
    }

    return res_idx;
}

vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
    int m = wordsContainer.size();
    int n = wordsQuery.size();

    vector<int> res(n);

    // step 1 - build the suffix trie by inserting all container words in order.
    trieNode* root = getNode(0);
    for(int i=0; i<m; i++){
        int idx = root->idx;

        // step 2 - ensure root->idx tracks the shortest word index among inserted words.
        if(wordsContainer[idx].length() > wordsContainer[i].length()){
            root->idx = i;
        }

        // step 3 - insert into trie's node
        insertInTrie(root, i, wordsContainer);
    }

    // step 4 - answer each query by searching the trie for the longest suffix match.
    for(int i=0; i<n; i++){
        res[i] = serachInTrie(root, wordsQuery[i]);
    }

    // step 5 - delete root
    delete root;

    // step 6 - return final result, `res`
    return res;
}

void printVector(vector<int>& vec){
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout<<vec[i];
        if (i < vec.size() - 1) {
            cout<<",";
        }
    }
    cout<< "]" <<endl;
}

int main(){
    // vector<string> wordsContainer = {"abcd", "bcd", "xbcd"};
    // vector<string> wordsQuery = {"cd","bcd","xyz"};

    vector<string> wordsContainer = {"abcdefgh","poiuygh","ghghgh"};
    vector<string> wordsQuery = {"gh","acbfgh","acbfegh"};
    vector<int> res = stringIndices(wordsContainer, wordsQuery);
    printVector(res);
    return 0;
}