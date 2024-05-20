
// Problem link - https://leetcode.com/problems/lru-cache/description/

package LinkedList_problems;

import java.util.*;

class CustomNodeUtil{
    int key;
    int value;
    CustomNodeUtil prev;
    CustomNodeUtil next;

    public CustomNodeUtil(int key, int value){
        this.key = key;
        this.value = value;
    }
}

class CustomDoublyLinkedList{
    CustomNodeUtil head;
    CustomNodeUtil tail;

    public CustomDoublyLinkedList(){
        head = new CustomNodeUtil(0, 0);
        tail = new CustomNodeUtil(0, 0);
        head.next = tail;
        tail.prev = head;
    }

    public CustomNodeUtil addAtHead(int key, int value){
        CustomNodeUtil newNode = new CustomNodeUtil(key, value);
        newNode.next = head.next;
        newNode.prev = head;
        head.next.prev = newNode;
        head.next = newNode;
        return newNode;
    }

    public void removeNode(CustomNodeUtil node){
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    public CustomNodeUtil removeAtTail(){
        CustomNodeUtil node = tail.prev;
        removeNode(node);
        return node;
    }
}

public class LRUCache {
    private Map<Integer, CustomNodeUtil> cacheMap;
    private CustomDoublyLinkedList dll;
    private int cacheCapacity;
    
    public LRUCache(int capacity){
        this.cacheCapacity = capacity;
        this.cacheMap = new HashMap<>();
        this.dll = new CustomDoublyLinkedList();
    }

    public int get(int key) {
        // if the key doesn't exist in cache then return -1
        if(!cacheMap.containsKey(key)) return -1;
        // otherwise get value from cache using key(node reference)
        int res = cacheMap.get(key).value;
        // Remove the node from its current place in the DLL
        CustomNodeUtil nodeToBeRemoved = cacheMap.get(key);
        dll.removeNode(nodeToBeRemoved);
        // Add the node at the head of the DLL with the current result value
        cacheMap.put(key, dll.addAtHead(key, res));
        // Return the result
        return res;
    }
    
    public void put(int key, int value) {
        if(cacheMap.containsKey(key)){
            // if the key already exist in cache map then remove existing one
            CustomNodeUtil nodeToBeRemoved = cacheMap.get(key);
            dll.removeNode(nodeToBeRemoved);
            // and add new entry corresponding to key
            cacheMap.put(key, dll.addAtHead(key, value));
        }else{
            // otherwise new key, value pair to be added in cache map
            // before adding new entry, we will check cacheCapacity
            if(cacheMap.size() == cacheCapacity){
                // if cache is full then delete LRU element that is at tail of DLL
                CustomNodeUtil tailNode = dll.removeAtTail();
                // remove the entry from cache map
                cacheMap.remove(tailNode.key);
            }
            CustomNodeUtil newNode = dll.addAtHead(key, value);
            cacheMap.put(key, newNode);
        }
    }

    public static void main(String[] args) {
        LRUCache lRUCache = new LRUCache(2);
        lRUCache.put(1, 1); // cache is {1=1}
        lRUCache.put(2, 2); // cache is {1=1, 2=2}
        System.out.println(lRUCache.get(1)); // return 1
        lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
        System.out.println(lRUCache.get(2)); // returns -1 (not found)
        lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
        System.out.println(lRUCache.get(1)); // return -1 (not found)
        System.out.println(lRUCache.get(3)); // return 3
        System.out.println(lRUCache.get(4)); // return 4
    }
}