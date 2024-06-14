
// Problem link - https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/

#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* left; // represents bit 0
    TrieNode* right; // represents bit 1

    TrieNode(){
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinaryTrie {
private:
    TrieNode* root;

public:
    BinaryTrie(){
        this->root = new TrieNode();
    }

    // utility method to insert a number (in binary) into the trie
    void insertIntoBinaryTrie(int num){
        TrieNode* curr = this->root;

        // iterate on 32-bit binary numbers, starting from MSB
        for(int i=31; i>=0; i--){
            // find the ith bit of the number 'num' to be inserted into the trie
            int bit = (num >> i) & 1;

            // insert into binary trie on the basis of bit value
            if(bit == 0){
                // ith bit is 0, insert into the left child of trie node
                if(curr->left == nullptr){
                    curr->left = new TrieNode();
                }
                curr = curr->left;
            }else{
                // otherwise, ith bit is 1, insert into the right child of trie node
                if(curr->right == nullptr){
                    curr->right = new TrieNode();
                }
                curr = curr->right;
            }
        }
    }

    // utility method to find the maximum XOR for a given number 'num'
    int findMaxXorValue(int num){
        TrieNode* temp = this->root;
        int max_xor = 0;

        // Iterate on 32-bit binary numbers, starting from MSB
        for(int i=31; i>=0; i--){
            // find the ith bit of the number 'num'
            int bit = (num >> i) & 1;

            // calculate maximum xor value on the basis of bit value
            if(bit == 0){
                // ith bit is 0, look into the right child of trie node for maximum XOR value
                if(temp->right != nullptr){
                    temp = temp->right;

                    // add ith bit contribution to the maximum XOR value 'max_xor'
                    max_xor += (1 << i);
                }else{
                    // otherwise, look into the left child of trie node
                    temp = temp->left;
                }
            }else{
                // ith bit is 1, look into the left child of trie node for maximum XOR value
                if(temp->left != nullptr){
                    temp = temp->left;

                    // Add ith bit contribution to the maximum XOR value 'max_xor'
                    max_xor += (1 << i);
                }else{
                    // otherwise, look into the right child of trie node
                    temp = temp->right;
                }
            }
        }

        // return the maximum XOR value
        return max_xor;
    }
};

int findMaximumXOR(vector<int>& nums) {
    int max_xor_ans = 0;
    BinaryTrie bt;
    for(int num : nums){
        bt.insertIntoBinaryTrie(num);
        max_xor_ans = max(max_xor_ans, bt.findMaxXorValue(num));
    }
    return max_xor_ans;
}

int main(){
    // vector<int> nums = {3, 10, 5, 25, 2, 8};

    // vector<int> nums = {4, 6, 7};

    vector<int> nums = {14,70,53,83,49,91,36,80,92,51,66,70};
    cout<<findMaximumXOR(nums)<<endl;
    return 0;
}