
// Problem link - https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/

class TrieNode {
    constructor(){
        // represents bit 0
        this.left = null;
        // represents bit 1
        this.right = null;
    }
}

class BinaryTrie {
    constructor(){
        this.root = new TrieNode();
    }

    // utility method to insert number (in binary) into trie
    insertIntoBinaryTrie(num){
        let curr = this.root;
        // iterate on 32-bits binary numbers, we will start from MSB
        for(let i=31; i>=0; i--){
            // find ith bit of number 'num' that will be inserted into Trie
            const bit = (num >> i) & 1;
            if(bit === 0){
                // i-th bit is 0, so will insert into left child of trie node
                if(curr.left === null){
                    curr.left = new TrieNode();
                }
                curr = curr.left;
            }else{
                // otherwise i-th bit is 1, so will insert into right child of trie node
                if(curr.right === null){
                    curr.right = new TrieNode();
                }
                curr = curr.right;
            }
        }
    }

    // utility method to find maximum XOR for a given number 'num'
    findMaxXorValue(num){
        let temp = this.root;
        let max_xor = 0;
        // iterate on 32-bits binary numbers, we will start from MSB
        for(let j=31; j>=0; j--){
            // find ith bit of number 'num'
            const bit = (num >> j) & 1;
            if(bit === 0){
                // i-th bit is 0 so we need to look into the right child of trie node for maximum XOR value
                if(temp.right){
                    temp = temp.right;
                    // add i-th bit contribution to the maximum XOR value 'max_xor'
                    max_xor += (1 << j);
                }else{
                    // otherwise look into the left child of trie node only
                    temp = temp.left;
                }
            }else{
                // i-th bit is 1 so we need to look into the left child of trie node for maximum XOR value
                if(temp.left){
                    temp = temp.left;
                    // add i-th bit contribution to the maximum XOR value 'max_xor'
                    max_xor += (1 << j);
                }else{
                    // otherwise look into the right child of trie node only
                    temp = temp.right;
                }
            }
        }
        // return maximum XOR value
        return max_xor;
    }
}

let findMaximumXOR = function(nums) {
    let max_xor_ans = 0;
    const btn = new BinaryTrie();
    for(let i=0; i<nums.length; i++){
        btn.insertIntoBinaryTrie(nums[i]);
        max_xor_ans = Math.max(max_xor_ans, btn.findMaxXorValue(nums[i]));
    }
    return max_xor_ans;
};

// let arr = [3, 10, 5, 25, 2, 8];

let arr = [14,70,53,83,49,91,36,80,92,51,66,70]
console.log(findMaximumXOR(arr));