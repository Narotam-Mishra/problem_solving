
// Implement your own HashMap using Hashing function

/*

Implementation Approach :-
1). Create structure that should contain array of Linked List
2). use Load factor (lambda), at any point of time if load factor > 0.5 then we rehash

*/

package Hashing_and_HashMap_problems;

class Node {
    String key;
    int value;
    Node next;

    public Node(String key, int value){
        this.key = key;
        this.value = value;
        this.next = null;
    }
}

class MyLinkedList {
    Node head;

    // constructor to intialize the LL's node
    public MyLinkedList(){
        this.head = null;
    }

    // utility method to add LL's node at head
    public void addAtHead(String key, int value){
        Node newNode = new Node(key, value);
        newNode.next = head;
        head = newNode;
    }

    // utility method to delete LL's node from head of LL
    public void deleteAtHead(){
        if(head == null) return;
        Node nodeToBeDel = head;
        head = head.next;
        nodeToBeDel.next = null;
    }
}

class HashMapUtils{
    private double lambdaFactorThreshold = 0.5;
    private double lambdaFactorLowerThreshold = 0.25;
    private int maxSize = 2;
    private MyLinkedList[] arr;
    private int currSize;

    public HashMapUtils(){
        arr = new MyLinkedList[maxSize];
        for(int i=0; i<maxSize; i++){
            arr[i] = new MyLinkedList();
        }
        currSize = 0;
    }

    // utility function to hash hashMap's key
    private int hashFunction(String key){
        // this 'hashedValue' will be the final hashed value
        int hashedValue = 0;
        int primeNo = 101;
        int pow = 1;
        int C = maxSize;

        // iterate on each character of input key
        for(int i=0; i<key.length(); i++){
            int asciiValue = getASCIIValue(key, i);
            hashedValue = (hashedValue % C + ((asciiValue % C) * (pow % C) % C)) % C;
            
            // for next iteration we will increment the power
            pow = (pow % C * primeNo % C) % C;
        }
        // return hashed value
        return hashedValue;
    }

     // utility function to find ASCII of a character
    private int getASCIIValue(String key, int index){
        return key.charAt(index);
    }

    // utility function to display HashMap's key-value pair entries
    public void display(){
        for(int i=0; i<arr.length; i++){
            Node temp = arr[i].head;
            StringBuilder str = new StringBuilder("LL: ");
            while(temp != null){
                str.append("(").append(temp.key).append(",").append(temp.value).append(")-->");
                temp = temp.next;
            }
            System.out.println(str);
        }
        System.out.println("Current size: "+currSize + " "+ "Maximum size: " + maxSize);
        System.out.println("**************");
    }

    // utility function to update hash map existing value
    public void update(String key, int value){
        // we assume that key is always present
        int bucketIndex = hashFunction(key);

        Node temp = arr[bucketIndex].head;
        while(temp != null){
            if(temp.key.equals(key)){
                temp.value = value;
            }
            temp = temp.next;
        }
    }

    // utility method to insert into HashMap
    public void insert(String key, int value){
        if(search(key) != null){
            // key already present, so no need to insert just update
            update(key, value);
            return;
        }

        double newLoadFactor = (double) (currSize + 1) / maxSize;
        if(newLoadFactor > lambdaFactorThreshold){
            // if after insertion of new key-value pair exceed the load factor beyound the threshold
            // then we should first rehash then insert
            rehash();
        }

        // hash value generated by hashFunction() will give bucketIndex.
        int bucketIndex = hashFunction(key);

        // add key,value pair entry using LL's addAtHead() method
        arr[bucketIndex].addAtHead(key, value);
        
        // new pair added so the size of hashMap will increase
        currSize++;
    }

    // utility method to search key's value in HashMap
    public Integer search(String key){
        // get bucketIndex using hash function
        int bucketIndex = hashFunction(key);

        // get current node 'curr' of LL using 'bucketIndex'
        Node currNode = arr[bucketIndex].head;

        // iterate on LL
        while (currNode != null) {
            if(currNode.key.equals(key)){
                // key found, return corresponding value
                return currNode.value;
            }
            // move to next LL's node
            currNode = currNode.next;
        }
        // if key not found return null
        return null;
    }

    // utility method to rehash
    private void rehash(){
        rehash(2);
    }

    // utility method to rehash the HashMap if it exceed its load factor
    private void rehash(double factor){
        // double the capacity of the array 'arr'
        maxSize *= factor;
        
        // new array with updated capacity
        MyLinkedList[] newArr = new MyLinkedList[maxSize];
        for(int i=0; i<maxSize; i++){
            newArr[i] = new MyLinkedList();
        }

        // iterate on each node of every LL from oldArr and insert them into new array 'newArr'
        for(MyLinkedList bucket : arr){
            // go to each bucket of old array, each bucket has linked list
            Node temp = bucket.head;

            while(temp != null){
                // find bucket index for new array
                int bucketIndex = hashFunction(temp.key);
                
                // add key-value pair into new array 'newArr'
                newArr[bucketIndex].addAtHead(temp.key, temp.value);
                
                // update next pointer while iterating
                temp = temp.next;
            }
        }
        // make this new array as out hashmap array
        arr = newArr;
    }
}

public class CustomHashMap {
    public static void main(String[] args) {
        
    }
}