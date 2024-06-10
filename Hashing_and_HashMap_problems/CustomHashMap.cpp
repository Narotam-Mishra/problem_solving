
// Implement your own HashMap using Hashing function

/*

Implementation Approach :-
1). Create structure that should contain array of Linked List
2). use Load factor (lambda), at any point of time if load factor > 0.5 then we rehash

*/

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    string key;
    int value;
    Node* next;

    Node(string k, int v){
        this->key = k;
        this->value = v;
        this->next = nullptr;
    }
};

class MyLinkedList {
public:
    Node* head;

    // constructor to intialize the LL's node
    MyLinkedList(){
        head = nullptr;
    }

    // utility method to add LL's node at head
    void addAthead(string key, int value){
        Node* newNode = new Node(key, value);
        newNode->next = head;
        head = newNode;
    }

    // utility method to delete LL's node from head of LL
    void deleteAtHead(){
        if(head == nullptr) return;
        Node* nodeToDel = head;
        head = head->next;
        delete nodeToDel;
    }
};

class HashMap{
private:
    double lambdaFactorThreshold = 0.5;
    double lambdaFactorLowerThreshold = 0.25;
    int maxSize = 2;
    vector<MyLinkedList*> arr;
    int currSize;

    // utility function to hash hashMap's key
    int hashFunction(const string& key){
        int hashedValue = 0;
        int primeNo = 101;
        int pow = 1;
        int C = maxSize;

        // iterate on each character of input key
        for(int i=0; i < key.length(); i++){
            int asciiValue = getASCIIValue(key, i);
            hashedValue = (hashedValue + asciiValue * pow) % C;

            // for next iteration we will increment the power
            pow = (pow * primeNo) % C;
        }
        // return hashed value
        return abs(hashedValue % C);
    }

    // utility function to find ASCII of a character
    int getASCIIValue(const string& key, int index){
        return key[index];
    }

     // utility method to rehash the HashMap if it exceed its load factor
    void rehash(double factor = 2.0){
        int oldSize = maxSize;

        // double the capacity of the array 'arr'
        maxSize = static_cast<int>(maxSize * factor);

        // new array with updated capacity
        vector<MyLinkedList*> newArr(maxSize, nullptr);
        for (int i = 0; i < maxSize; ++i) {
            newArr[i] = new MyLinkedList();
        }

        // iterate on each node of every LL from oldArr and insert them into new array 'newArr'
        for(int i=0; i < oldSize; i++){
            // go to each bucket of old array, each bucket has linked list
            Node* temp = arr[i]->head;

            while(temp != nullptr){
                // extract key & value
                string key = temp->key;
                int value = temp->value;

                // find bucket index for new array
                int bucketIndex = hashFunction(key);

                // add key-value pair into new array 'newArr'
                newArr[bucketIndex]->addAthead(key, value);
                
                // update next pointer while iterating
                temp = temp->next;
            }
            // free old linked list
            delete arr[i]; 
        }
        // make this new array as out hashmap array
        arr = newArr;
    }

public:
    HashMap(){
        arr.resize(maxSize, nullptr);
        for (int i = 0; i < maxSize; ++i) {
            arr[i] = new MyLinkedList();
        }
        currSize = 0;
    }

    // destructor function to release the memory
    ~HashMap() {
        for (int i = 0; i < maxSize; ++i) {
            delete arr[i];
        }
    }

    int search(const string& key){
        // get bucketIndex using hash function
        int bucketIndex = hashFunction(key);
        
        // get current node 'curr' of LL using 'bucketIndex'
        Node* currNode = arr[bucketIndex]->head;

        // iterate on LL
        while(currNode != nullptr){
            if(currNode->key == key){
                // key found, return corresponding value
                return currNode->value;
            }
            // move to next LL's node
            currNode = currNode->next;
        }

        // if key not found return -1
        return -1;
    }

    // utility function to update hash map existing value
    void update(const string& key, int value){
        // we assume that key is always present
        int bucketIndex = hashFunction(key);

        Node* temp = arr[bucketIndex]->head;
        while(temp != nullptr){
            if(temp->key == key){
                temp->value = value;
                return;
            }
            temp = temp->next;
        }
    }

    // utility method to insert into HashMap
    void insert(const string& key, int value){
        if(search(key) != -1){
            // key already present, so no need to insert just update
            update(key, value);
            return;
        }

        double newLoadFactor = static_cast<double>(currSize + 1) / maxSize;
        if(newLoadFactor > lambdaFactorThreshold){
            // if after insertion of new key-value pair exceed the load factor beyound the threshold
            // then we should first rehash then insert
            rehash();
        }

        // hash value generated by hashFunction() will give bucketIndex.
        int bucketIndex = hashFunction(key);

        // add key,value pair entry using LL's addAtHead() method
        arr[bucketIndex]->addAthead(key, value);

        // new pair added so the size of hashMap will increase
        currSize++;
    }

    // utility method to remove(key,value pair entry) from HashMap
    void remove(const string& key){
        /**
        * 1. Check if the key is even present or not ?
        * 2. If the key is present, check in which ll bucket it is, using hash function
        * 3. Iterate on the LL and remove the node
        */

       // step - 1
       int value = search(key);
       if(value == -1){
        cout<<"Key is not present, nothing to remove"<<endl;
        return;
       }

       // step - 2
       int bucketIndex = hashFunction(key);
       Node* temp = arr[bucketIndex]->head;

       // 2.1 - check LL to find key
       if(temp->key == key){
        // head node need to be deleted
        arr[bucketIndex]->deleteAtHead();
        
        // 2.2 - decrease current size of hash map
        currSize--;

        // 2.3 - after decrement , recalculate load factor
        double loadFactor = static_cast<double>(currSize) / maxSize;
        if(loadFactor <= lambdaFactorLowerThreshold){
            //2.4 - if current load factor is less than lower load factor value then rehash()
            rehash(0.5);
        }
        return;
       }

       // step - 3
       while(temp != nullptr){
        //3.1 - check if the curr node is just behind the node to be deleted ?
        if(temp->next != nullptr && temp->next->key == key){
            Node* nodeToBeDel = temp->next;
            
            //3.2 - attach prev node to next node
            temp->next = nodeToBeDel->next;
            
            //3.3 - break the LL connection
            delete nodeToBeDel;

            // 3.4 - decrement current size of hash map
            currSize--;

            //3.5 - after decrement , recalculate load factor
            double loadFactor = static_cast<double>(currSize) / maxSize;
            if(loadFactor <= lambdaFactorLowerThreshold){
                //3.6 - if current load factor is less than lower load factor value, then rehash()
                rehash(0.5);
            }
            return;
        }
        // move forward in LL
        temp = temp->next;
       }
    }

    // utility function to display HashMap's key-value pair entries
    void display(){
        for(int i=0; i<arr.size(); i++){
            Node* temp = arr[i]->head;
            cout<<"LL: ";
            while(temp != nullptr){
                cout<<"("<<temp->key<<","<<temp->value<<") -->";
                temp = temp->next;
            }
            cout<<endl;
        }
        cout<<"Current size: "<<currSize<<" "<<"Maximum size: "<<maxSize<<endl;
        cout << "**************" << endl;
    }
};

int main(){
    HashMap hm;
    hm.insert("mango", 21);
    hm.display();
    hm.insert("chiku", 11);
    hm.display();
    hm.insert("apple", 31);
    hm.display();
    hm.insert("grapes", 51);
    hm.display();
    hm.insert("Pineapple", 61);
    hm.display();

    cout << hm.search("Orange") << endl;

    hm.remove("chiku");
    hm.display();

    hm.update("mango", 49);
    hm.display();
    return 0;
}