
// Problem link - https://leetcode.com/problems/lru-cache/description/

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int key, int value){
        this->key = key;
        this->value = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList{
public:
    Node* head;
    Node* tail;

    DoublyLinkedList(){
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }

    Node* addAtHead(int key, int value){
        // newNode-->curNode-->nextNode
        Node* newNode = new Node(key, value);
        newNode->next = head->next;
        newNode->prev = head;
        head->next->prev = newNode;
        head->next = newNode;
        return newNode;
    }

    void removeNode(Node* node){
        // prevNode-->node-->nextNode
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    Node* removeAtTail(){
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }
};

class LRUCache{
private:
    unordered_map<int, Node*> cacheMap;
    DoublyLinkedList dll;
    int cacheCapapcity;

public:
    LRUCache(int capacity) {
        this->cacheCapapcity = capacity;
    }

    int get(int key){
        // if the key doesn't exist in cache then return -1
        if(!cacheMap.count(key)) return -1;
        // otherwise get value from cache using key(node reference)
        int res = cacheMap[key]->value;
        // Remove the node from its current place in the DLL
        dll.removeNode(cacheMap[key]);
        // Add the node at the head of the DLL with the current result value
        cacheMap[key] = dll.addAtHead(key, res);
        // return value corresponding to key
        return res;
    }

    void put(int key, int value){
        if(cacheMap.count(key)){
            // if the key already exist in cache map then remove existing one
            dll.removeNode(cacheMap[key]);
            // and update new value corresponding to key
            cacheMap[key] = dll.addAtHead(key,value);
        }else{
            // new key, value pair to be added in cache map
            // before adding new entry, we will check cacheCapacity
            if(cacheMap.size() == cacheCapapcity){
                // if cache is full then delete LRU element that is at tail of DLL
                Node* tailNode = dll.removeAtTail();
                // remove the entry from cache map
                cacheMap.erase(tailNode->key);
                delete tailNode;
            }
            // and add new value corresponding to key
            cacheMap[key] = dll.addAtHead(key, value);
        }
    }
};

int main() {
    LRUCache lRUCache(2);
    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    cout<<lRUCache.get(1)<<endl; // return 1
    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    cout<<lRUCache.get(2)<<endl; // returns -1 (not found)
    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    cout<<lRUCache.get(1)<<endl; // return -1 (not found)
    cout<<lRUCache.get(3)<<endl; // return 3
    cout<<lRUCache.get(4)<<endl; // return 4
    return 0;
}