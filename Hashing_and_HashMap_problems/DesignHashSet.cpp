
// Problem link : https://leetcode.com/problems/design-hashset/description/?envType=problem-list-v2&envId=hash-table

#include<bits/stdc++.h>
using namespace std;

// Approach - 1
class MyHashSet1 {
private:
    int size;
    vector<list<int>> buckets;

    // hash function to compute bucket index
    int hash(int key){
        return key % size;
    }

public:
    // intialization using constructor 
    MyHashSet1() {
        // number of buckets
        size = 1000;
        buckets.resize(size);
    }
    
    void add(int key) {
        // get bucket index
        int index = hash(key);
        list<int>& bucket = buckets[index];

        // add the key if it's not already present
        if(find(bucket.begin(), bucket.end(), key) == bucket.end()){
            bucket.push_back(key);
        }
    }
    
    void remove(int key) {
        // get bucket index
        int index = hash(key);
        list<int>& bucket = buckets[index];

        // remove the key if it exist
        bucket.remove(key);
    }
    
    bool contains(int key) {
        // get bucket index
        int index = hash(key);
        list<int>& bucket = buckets[index];

        // check if key exists
        return find(bucket.begin(), bucket.end(), key) != bucket.end();
    }
};

// Approach - 2

class MyHashSet {
private:
    // boolean array to represent the presence of keys
    vector<bool> map; 

public:
    // constructor to initialize the boolean array with size 1,000,001
    MyHashSet() {
        map.resize(1000001, false);
    }
    
    // add the key to the HashSet
    void add(int key) {
        map[key] = true;
    }
    
    // remove the key from the HashSet
    void remove(int key) {
        map[key] = false;
    }
    
    // check if the key is present in the HashSet
    bool contains(int key) {
        return map[key];
    }
};

int main(){
    MyHashSet hashSet;
    hashSet.add(1);
    hashSet.add(2);
    cout << hashSet.contains(1) << endl; // true - 1
    cout << hashSet.contains(3) << endl; // false - 0
    hashSet.add(3);
    cout << hashSet.contains(3) << endl; // true - 1
    hashSet.remove(2);
    cout << hashSet.contains(2) << endl; // false - 0

    return 0;
}