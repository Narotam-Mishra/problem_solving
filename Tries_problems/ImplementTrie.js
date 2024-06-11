
// Problem link - https://leetcode.com/problems/implement-trie-prefix-tree/

class TrieNode{
    constructor(data){
        this.data = data;
        this.isTerminal = false;
        this.children = {};
    }
}

let Trie = function() {
    this.root = new TrieNode(null);
};

/** 
 * @param {string} word
 * @return {void}
 */
Trie.prototype.insert = function(word) {
    let curr = this.root;
    for(let i=0; i<word.length; i++){
        let ch = word[i];
        if(curr.children[ch]){
            // if child 'char' is present , then we move to that child
            curr = curr.children[ch];
        }else{
            // otherwise if child 'char' is not present then we create a new TrieNode
            let newTrieNode = new TrieNode(ch);
            
            // add char to the children map
            curr.children[ch] = newTrieNode;

            // move to next trie node
            curr = curr.children[ch];
        }
    }
    // when the loop ends 'curr' will be at last trie node's char
    curr.isTerminal = true;
};

/** 
 * @param {string} word
 * @return {boolean}
 */
Trie.prototype.search = function(word) {
    let curr = this.root;
    for(let i=0; i<word.length; i++){
        let ch = word[i];
        if(curr.children[ch]){
            curr = curr.children[ch];
        }else{
            return false;
        }
    }
    return curr.isTerminal;
};

/** 
 * @param {string} prefix
 * @return {boolean}
 */
Trie.prototype.startsWith = function(prefix) {
    let currNode = this.root;
    for(let ch of prefix){
        if(!currNode.children[ch]){
            return false;
        }
        currNode = currNode.children[ch];
    }
    return true;
};

function main(){
    const trie = new Trie();
    const wordsToInsert = ["apple", "app", "application", "apex", "banana", "bat"];
    const wordsToSearch = ["app", "apple", "bat", "bath"];
    const prefixesToCheck = ["ap", "ba", "cat"];

    console.log("Inserting words into the Trie with enthusiasm:");
    for (const word of wordsToInsert) {
        console.log(`Inserting: ${word}`);
        trie.insert(word);
    }

    console.log("\nSearching for words in the Trie with great anticipation:");
    for (const word of wordsToSearch) {
        const found = trie.search(word);
        console.log(`Searching for "${word}": ${found ? "Found!" : "Not found!"}`);
    }

    console.log("\nChecking prefixes in the Trie with bated breath:");
    for (const prefix of prefixesToCheck) {
        const hasPrefix = trie.startsWith(prefix);
        console.log(`Checking prefix "${prefix}": ${hasPrefix ? "Exists!" : "Does not exist!"}`);
    }
}

main();