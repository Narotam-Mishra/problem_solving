
// Problem link - https://leetcode.com/problems/design-hashmap/

#include<bits/stdc++.h>
using namespace std;

class MyHashMap {
private:
    int size;
    vector<list<pair<int, int>>> buckets;

    // utility hash function to compute the bucket index for a given key
    int hash(int key){
        return key % size;
    }

public:
    MyHashMap() {
        size = 1000;
        buckets.resize(size);
    }

    // utility method to add entry into hashmap
    void put(int key, int value) {
        // get the bucket index for the given key
        int index = hash(key);

        // get the list of pairs for the given bucket index
        for(auto& pair : buckets[index]){
            if(pair.first == key){
                pair.second = value;
                return;
            }
        }

        // if the key is not present in the list, add the key-value pair to the list
        buckets[index].emplace_back(key, value);
    }

    // utility method to get the value for a given key from hashmap
    int get(int key) {
        // get the bucket index for the given key
        int index = hash(key);

        // get the list of pairs for the given bucket index
        for(const auto& pair : buckets[index]){
            if(pair.first == key){
                return pair.second;
            }
        }

        // if the key is not present in the list, return -1
        return -1;
    }

    // utility method to remove the key-value pair from hashmap
    void remove(int key) {
        // get the bucket index for the given key
        int index = hash(key);

        // remove key-value pair entry if it exists in the list
        buckets[index].remove_if([key](const pair<int, int>& pair){
            return pair.first == key;
        });
    }
};

int main(){
    MyHashMap hm;
    
    // Test case 1: Basic insertion and retrieval
    cout << "Test 1: Basic insertion and retrieval" << endl;
    hm.put(1, 10);
    hm.put(2, 20);
    cout << "Value for key 1: " << hm.get(1) << endl; // Expected: 10
    cout << "Value for key 2: " << hm.get(2) << endl; // Expected: 20
    cout << "Value for non-existent key 3: " << hm.get(3) << endl; // Expected: -1

    // Test case 2: Update value for existing key
    cout << "\nTest 2: Update value for existing key" << endl;
    hm.put(2, 25);
    cout << "Updated value for key 2: " << hm.get(2) << endl; // Expected: 25

    // Test case 3: Remove a key
    cout << "\nTest 3: Remove a key" << endl;
    hm.remove(1);
    cout << "Value for removed key 1: " << hm.get(1) << endl; // Expected: -1
    cout << "Value for key 2: " << hm.get(2) << endl; // Expected: 25

    // Test case 4: Handle collisions
    cout << "\nTest 4: Handle collisions" << endl;
    hm.put(1001, 50); // 1001 % 1000 = 1, collides with key 1
    hm.put(2001, 60); // 2001 % 1000 = 1, collides with key 1
    cout << "Value for key 1001: " << hm.get(1001) << endl; // Expected: 50
    cout << "Value for key 2001: " << hm.get(2001) << endl; // Expected: 60

    // Test case 5: Remove a key from a bucket with collisions
    cout << "\nTest 5: Remove a key from a bucket with collisions" << endl;
    hm.remove(1001);
    cout << "Value for removed key 1001: " << hm.get(1001) << endl; // Expected: -1
    cout << "Value for key 2001: " << hm.get(2001) << endl; // Expected: 60

    // Test case 6: Edge case with very large keys
    cout << "\nTest 6: Edge case with very large keys" << endl;
    hm.put(1000001, 100);
    cout << "Value for large key 1000001: " << hm.get(1000001) << endl; // Expected: 100
    hm.remove(1000001);
    cout << "Value for removed large key 1000001: " << hm.get(1000001) << endl; // Expected: -1

    cout << "\nAll tests completed." << endl;

    return 0;
}