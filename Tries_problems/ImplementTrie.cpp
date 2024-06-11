
// Problem link - https://leetcode.com/problems/implement-trie-prefix-tree/

#include<bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    char data;
    bool isTerminal;
    unordered_map<char, TrieNode*> children;

    TrieNode(char data){
        this->data = data;
        this->isTerminal = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        // root node doesn't contain any character
        root = new TrieNode('\0');
    }
    
    // function to insert a word into the Trie
    void insert(string word) {
        TrieNode* curr = root;

        // iterate on each character of word
        for(char ch : word){
            // if child 'char' is absent , then we create a new TrieNode
            if(curr->children.find(ch) == curr->children.end()){
                curr->children[ch] = new TrieNode(ch);
            }
            // if child 'char' is present , then we move to that child
            curr = curr->children[ch];
        }
        // mark the end of the word
        curr->isTerminal = true;
    }
    
    // function to search a word in the Trie
    bool search(string word) {
        TrieNode* curr = root;
        for(char ch : word){
            if(curr->children.find(ch) == curr->children.end()){
                return false;
            }
            curr = curr->children[ch];
        }
        // only return true if it's the end of a word
        return curr->isTerminal;
    }
    
    // function to check if there is any word in the Trie that starts with the given prefix
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char ch : prefix){
            if(curr->children.find(ch) == curr->children.end()){
                return false;
            }
            curr = curr->children[ch];
        }
        return true;
    }
};

int main() {
    Trie trie;
    vector<string> wordsToInsert = { "apple", "app", "application", "apex", "banana", "bat" };
    vector<string> wordsToSearch = { "app", "apple", "bat", "bath" };
    vector<string> prefixesToCheck = { "ap", "ba", "cat" };

    cout << "Inserting words into the Trie with enthusiasm:" << endl;
    for (const string& word : wordsToInsert) {
        cout << "Inserting: " << word << endl;
        trie.insert(word);
    }

    cout << "\nSearching for words in the Trie with great anticipation:" << endl;
    for (const string& word : wordsToSearch) {
        bool found = trie.search(word);
        cout << "Searching for \"" << word << "\": " << (found ? "Found!" : "Not found!") << endl;
    }

    cout << "\nChecking prefixes in the Trie with bated breath:" << endl;
    for (const string& prefix : prefixesToCheck) {
        bool hasPrefix = trie.startsWith(prefix);
        cout << "Checking prefix \"" << prefix << "\": " << (hasPrefix ? "Exists!" : "Does not exist!") << endl;
    }
    return 0;
}