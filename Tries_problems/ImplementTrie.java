
// Problem link - https://leetcode.com/problems/implement-trie-prefix-tree/

package Tries_problems;

import java.util.*;

class TrieUtil {
    char data;
    boolean isTerminal;
    Map<Character, TrieUtil> children;

    public TrieUtil(char data){
        this.data = data;
        this.isTerminal = false;
        this.children = new HashMap<>();
    }
}

class Trie {
    private TrieUtil root;

    public Trie() {
        root = new TrieUtil('\0');
    }
    
    // method to insert a word into the Trie
    public void insert(String word) {
        TrieUtil current = root;
        // iterate on each character of word
        for(char ch : word.toCharArray()){
            // if child 'char' is absent , then we create a new TrieNode
            current.children.putIfAbsent(ch, new TrieUtil(ch));
            // if child 'char' is present , then we move to that child
            current = current.children.get(ch);
        }
        // mark the end of the word
        current.isTerminal = true;
    }
    
    // method to search a word in the Trie
    public boolean search(String word) {
        TrieUtil curr = root;
        for(char ch : word.toCharArray()){
            if(!curr.children.containsKey(ch)){
                return false;
            }
            curr = curr.children.get(ch);
        }
        // Only return true if it's the end of a word
        return curr.isTerminal;
    }
    
    // method to check if there is any word in the Trie that starts with the given prefix
    public boolean startsWith(String prefix) {
        TrieUtil curr = root;
        for(char ch : prefix.toCharArray()){
            if(!curr.children.containsKey(ch)){
                return false;
            }
            curr = curr.children.get(ch);
        }
        return true;
    }
}

public class ImplementTrie {
    public static void main(String[] args) {
        Trie trie = new Trie();
        String[] wordsToInsert = {"apple", "app", "application", "apex", "banana", "bat"};
        String[] wordsToSearch = {"app", "apple", "bat", "bath"};
        String[] prefixesToCheck = {"ap", "ba", "cat"};

        System.out.println("Inserting words into the Trie with enthusiasm:");
        for (String word : wordsToInsert) {
            System.out.println("Inserting: " + word);
            trie.insert(word);
        }

        System.out.println("\nSearching for words in the Trie with great anticipation:");
        for (String word : wordsToSearch) {
            boolean found = trie.search(word);
            System.out.println("Searching for \"" + word + "\": " + (found ? "Found!" : "Not found!"));
        }

        System.out.println("\nChecking prefixes in the Trie with bated breath:");
        for (String prefix : prefixesToCheck) {
            boolean hasPrefix = trie.startsWith(prefix);
            System.out.println("Checking prefix \"" + prefix + "\": " + (hasPrefix ? "Exists!" : "Does not exist!"));
        }
    }
}