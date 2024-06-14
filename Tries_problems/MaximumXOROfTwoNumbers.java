
// Problem link - https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/

package Tries_problems;

class TrieNode {
    // represents bit 0
    TrieNode left;

    // represents bit 0
    TrieNode right;

    public TrieNode(){
        this.left = null;
        this.right = null;
    }
}

class BinaryTrie {
    private TrieNode root;

    public BinaryTrie(){
        this.root = new TrieNode();
    }

    // utility method to insert a number (in binary) into the trie
    public void insertIntoBinaryTrie(int num){
        TrieNode curr = this.root;

        // iterate on 32-bit binary numbers, starting from MSB
        for(int i=31; i>=0; i--){
            // find the ith bit of the number 'num' to be inserted into the trie
            int bit = (num >> i) & 1;
            if(bit == 0){
                // ith bit is 0, insert into the left child of trie node
                if(curr.left == null){
                    curr.left = new TrieNode();
                }
                curr = curr.left;
            }else{
                // otherwise, ith bit is 1, insert into the right child of trie node
                if(curr.right == null){
                    curr.right = new TrieNode();
                }
                curr = curr.right;
            }
        }
    }

    // utility method to find the maximum XOR for a given number 'num'
    public int findMaxXorValue(int num){
        int max_xor = 0;
        TrieNode temp = this.root;

        // iterate on 32-bit binary numbers, starting from MSB
        for(int j=31; j>=0; j--){
            // find the ith bit of the number 'num'
            int bit = (num >> j) & 1;
            if(bit == 0){
                // ith bit is 0, look into the right child of trie node for maximum XOR value
                if(temp.right != null){
                    temp = temp.right;
                    // add ith bit contribution to the maximum XOR value 'max_xor'
                    max_xor += (1 << j);
                }else{
                    // otherwise, look into the left child of trie node
                    temp = temp.left;
                }
            }else{
                // ith bit is 1, look into the left child of trie node for maximum XOR value
                if(temp.left != null){
                    temp = temp.left;
                    // add ith bit contribution to the maximum XOR value 'max_xor'
                    max_xor += (1 << j);
                }else{
                    temp = temp.right;
                }
            }
        }
        return max_xor;
    }
}



public class MaximumXOROfTwoNumbers {

    public static int findMaximumXOR(int[] nums) {
        int max_xor_ans = 0;
        BinaryTrie bt = new BinaryTrie();
        for(int num : nums){
            bt.insertIntoBinaryTrie(num);
            max_xor_ans = Math.max(max_xor_ans, bt.findMaxXorValue(num));
        }
        return max_xor_ans;
    }

    public static void main(String[] args) {
        int[] nums = {3, 10, 5, 25, 2, 8};

        // int[] nums = {4, 6, 7};

        // int[] nums = {14,70,53,83,49,91,36,80,92,51,66,70};
        System.out.println(findMaximumXOR(nums));
    }
}
