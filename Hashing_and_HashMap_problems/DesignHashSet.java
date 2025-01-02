
// Problem link : https://leetcode.com/problems/design-hashset/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

class MyHashSet {
    private final int size;
    private final LinkedList<Integer>[] buckets;

    // intialization using constructor
    @SuppressWarnings("unchecked")
    public MyHashSet() {
        // number of buckets
        size = 1000;
        buckets = new LinkedList[size];

        // iterate over each bucket 
        for(int i=0; i<size; i++) {
            // and intialize it with linked list
            buckets[i] = new LinkedList<>();
        }
    }

    // hash function to compute the bucket index
    private int hash(int key) {
        return key % size;
    }
    
    public void add(int key) {
        // get bucket index
        int index = hash(key);
        LinkedList<Integer> bucket = buckets[index];

        // only add the key if it doesn't already exist in the bucket
        if(!bucket.contains(key)){
            bucket.add(key);
        }
    }
    
    public void remove(int key) {
        // get bucket index
        int index = hash(key);
        LinkedList<Integer> bucket = buckets[index];

        // remove the key if it exist
        bucket.remove((Integer) key);
    }
    
    public boolean contains(int key) {
        // get bucket index
        int index = hash(key);
        LinkedList<Integer> bucket = buckets[index];

        // check if the key exists in the bucket
        return bucket.contains(key);
    }
}

public class DesignHashSet {
    public static void main(String[] args) {
        MyHashSet hashSet = new MyHashSet();
        hashSet.add(1);
        hashSet.add(2);
        System.out.println(hashSet.contains(1)); // true
        System.out.println(hashSet.contains(3)); // false
        hashSet.add(3);
        System.out.println(hashSet.contains(3)); // true
        hashSet.remove(2);
        System.out.println(hashSet.contains(2)); // false
    }
}