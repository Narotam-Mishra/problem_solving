
// Problem link - https://leetcode.com/problems/design-hashmap/

package Hashing_and_HashMap_problems;

import java.util.*;

class MyHashMap {
    private class Pair{
        int key, value;
        Pair(int key, int value){
            this.key = key;
            this.value = value;
        }
    }

    private int size;
    private List<Pair>[] buckets;

    @SuppressWarnings("unchecked")
    public MyHashMap(){
        this.size = 1000;
        this.buckets = new LinkedList[size];
        for(int i=0; i<size; i++){
            buckets[i] = new LinkedList<Pair>();
        } 
    }

    // utility hash function to compute the bucket index for a given key
    private int hash(int key){
        return key % size;
    }

    // utility method to add entry into hashmap
    public void put(int key, int value){
        // get the bucket index for the given key
        int index = hash(key);

        // get the list of pairs for the given bucket index
        for(Pair pair : buckets[index]){
            if(pair.key == key){
                pair.value = value;
                return;
            }
        }

        // if the key is not present in the list, add the key-value pair to the list
        buckets[index].add(new Pair(key, value));
    }

    // utility method to get the value for a given key from hashmap
    public int get(int key){
        // get the bucket index for the given key
        int index = hash(key);

        // get the list of pairs for the given bucket index
        for(Pair pair : buckets[index]){
            if(pair.key == key){
                return pair.value;
            }
        }

        // if the key is not present in the list, return -1
        return -1;
    }

    // utility method to remove the key-value pair from hashmap
    public void remove(int key){
        int index = hash(key);
        buckets[index].removeIf(pair -> pair.key == key);
    }
}

public class DesignHashMap {
    public static void main(String[] args) {
        MyHashMap hm = new MyHashMap();
        
        // Test case 1: Basic insertion and retrieval
        System.out.println("Test 1: Basic insertion and retrieval");
        hm.put(1, 10);
        hm.put(2, 20);
        System.out.println("Value for key 1: " + hm.get(1)); // Expected: 10
        System.out.println("Value for key 2: " + hm.get(2)); // Expected: 20
        System.out.println("Value for non-existent key 3: " + hm.get(3)); // Expected: -1

        // Test case 2: Update value for existing key
        System.out.println("\nTest 2: Update value for existing key");
        hm.put(2, 25);
        System.out.println("Updated value for key 2: " + hm.get(2)); // Expected: 25

        // Test case 3: Remove a key
        System.out.println("\nTest 3: Remove a key");
        hm.remove(1);
        System.out.println("Value for removed key 1: " + hm.get(1)); // Expected: -1
        System.out.println("Value for key 2: " + hm.get(2)); // Expected: 25

        // Test case 4: Handle collisions
        System.out.println("\nTest 4: Handle collisions");
        hm.put(1001, 50); // 1001 % 1000 = 1, collides with key 1
        hm.put(2001, 60); // 2001 % 1000 = 1, collides with key 1
        System.out.println("Value for key 1001: " + hm.get(1001)); // Expected: 50
        System.out.println("Value for key 2001: " + hm.get(2001)); // Expected: 60

        // Test case 5: Remove a key from a bucket with collisions
        System.out.println("\nTest 5: Remove a key from a bucket with collisions");
        hm.remove(1001);
        System.out.println("Value for removed key 1001: " + hm.get(1001)); // Expected: -1
        System.out.println("Value for key 2001: " + hm.get(2001)); // Expected: 60

        // Test case 6: Edge case with very large keys
        System.out.println("\nTest 6: Edge case with very large keys");
        hm.put(1000001, 100);
        System.out.println("Value for large key 1000001: " + hm.get(1000001)); // Expected: 100
        hm.remove(1000001);
        System.out.println("Value for removed large key 1000001: " + hm.get(1000001)); // Expected: -1

        System.out.println("\nAll tests completed.");
    }
}
