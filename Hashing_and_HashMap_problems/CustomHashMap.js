
// Implement your own HashMap using Hashing function

/*

Implementation Approach :-
1). Create structure that should contain array of Linked List
2). use Load factor (lambda), at any point of time if load factor > 0.5 then we rehash

*/

let Node = function(key, value) {
    this.key = key; // key
    this.value = value;
    this.next = null; // until or unless we attach this new node to a list, the next property should be null
}


let MyLinkedList = function() {
    this.head = null; // because initially everything is empty
};

/** 
 * @param {number} val
 * @return {void}
 */
MyLinkedList.prototype.addAtHead = function(key, val) {
    if(this.head == null) {
        // means the ll is empty, so this node should become the head
        this.head = new Node(key, val);
    } else {
        // when ll is not. empty
        let n = new Node(key,  val);
        n.next = this.head;
        this.head = n;
    }
};

MyLinkedList.prototype.deleteAtHead = function() {
    if(this.head == null) return;
    let nextHead = this.head.next;
    let nodeToBeDelete = this.head; // curr head
    this.head = nextHead;
    nodeToBeDelete.next = null; // prev head disconnected
}

class HashMap {
    constructor(){
        // threshold lambda factor
        this.lambdaFactorThreshold = 0.5;
        this.lambdaFactorLowerThreshold = 0.25
        // how many buckets are avaialable
        this.maxSize = 2; 
        this.arr = Array(this.maxSize);
        // to know how many key-value pairs are inserted into hashMap (i.e size of HashMap)
        
        for(let i=0; i<this.maxSize; i++){
            // store empty LL at each index
            this.arr[i] = new MyLinkedList();
        }

        this.currSize = 0;
    }

    // this hashFunction(key) will takes key as parameter, apply hashFunction() logic on the key and
    // the result of this hashFunction will be the bucket index in the given array
    hashFunction(key){

        // (a + b)%c => (a%c + b%c)%c
        // (a * b)%c => (a%c * b%c)%c

        let hashedValue = 0;
        // this 'hashedValue' will be the final hashed value
        let primeNo = 101;
        // prime number to keep

        let pow = 1;
        // initially power p^0 i.e 1

        let C = this.maxSize;

        // iterate on each character of input key
        for (let i = 0; i < key.length; i++) {
            let asciiValue = this.getASCIIValue(key, i);
            hashedValue = ((hashedValue % C) + (((asciiValue % C) * (pow % C)) % C)) % C;

          // for next iteration we will increment the power
          pow = ((pow % C) * primeNo % C) % C;
        }
        return hashedValue;
    }

    // utility function to find ASCII of a character
    getASCIIValue(key, index){
        return key.charCodeAt(index);
    }

    // utility function to display HashMap's key-value pair entries
    display(){
        for(let i=0; i<this.arr.length; i++){
            let temp = this.arr[i].head;
            let str = "LL: ";
            while(temp !== null){
                str += "(" + temp.key + "," + temp.value + ") -->";
                temp = temp.next;
            }
            console.log(str);
        }
        console.log(this.currSize, this.maxSize);
        console.log("**************");
    }

    // utility function to update hash map existing value
    update(key,value){
        // we assume that key is always present
        const bucketIndex = this.hashFunction(key);
        let temp = this.arr[bucketIndex].head;
        while(temp !== null){
            if(temp.key === key){
                temp.value = value;
                return;
            }
            temp = temp.next;
        }
    }

    // utility method to insert into HashMap
    insert(key, value){
        // TODO: implement update function
        if(this.search(key)){
            // key already present, so no need to insert just update
            this.update(key, value);
            return;
        }

        let newLoadFactor = (this.currSize + 1) / this.maxSize;
        if(newLoadFactor > this.lambdaFactorThreshold){
            // if after insertion of new key-value pair exceed the load factor beyound the threshold
            // then we should first rehash then insert
            this.rehash();
        }

        // hash value generated by hashFunction() will give bucketIndex.
        const bucketIndex = this.hashFunction(key);
        
        // add key,value pair entry using LL's addAtHead() method
        this.arr[bucketIndex].addAtHead(key, value);

        // new pair added so the size of hashMap will increase
        this.currSize += 1;
    }

    // utility method to remove(key,value pair entry) from HashMap
    remove(key){
        /**
        * 1. Check if the key is even present or not ?
        * 2. If the key is present, check in which ll bucket it is, using hash function
        * 3. Iterate on the LL and remove the node
        */

        // step - 1
        const value = this.search(key);
        if(!value){
            console.log("Key is not present, nothing to remove");
            return;
        }

        // step - 2
        const bucketIndex = this.hashFunction(key);
        let temp = this.arr[bucketIndex].head;

        // 2.1 - check LL to find key
        if(temp.key === key){
            // head node need to be deleted
            this.arr[bucketIndex].deleteAtHead();
            // 2.2 - decrease current size of hash map
            this.currSize -= 1;
            // 2.3 - after decrement , recalculate load factor
            const loadFactor = (this.currSize) / this.maxSize;
            if(loadFactor <= this.lambdaFactorLowerThreshold){
                //2.4 - if current load factor is less than lower load factor value
                this.rehash(0.5);
            }
            return;
        }

        // step - 3
        while(temp !== null){
            //3.1 - check if the curr node is just behind the node to be deleted ?
            if(temp.next !== null && temp.next.key === key){
                const nodeToBeDel = temp.next;
                //3.2 - attach prev node to next node
                temp.next = nodeToBeDel.next;
                
                //3.3 - break the conn
                nodeToBeDel.next = null;

                // 3.4 - decrement current size of hash map
                this.currSize -= 1;

                //3.5 - after decrement , recalculate load factor
                const loadFactor = (this.currSize) / this.maxSize;

                if(loadFactor <= this.lambdaFactorLowerThreshold) {
                    //3.6 - if current load factor is less than lower load factor value
                    this.rehash(0.5);
                }
                return;
            }
            // move forward in LL
            temp = temp.next;
        }
    }

    // utility method to search key's value in HashMap
    search(key){
        // get bucketIndex using hash function
        const bucketIndex = this.hashFunction(key);

        // get current node 'curr' of LL using 'bucketIndex'
        let currNode = this.arr[bucketIndex].head;

        // iterate on LL
        while(currNode !== null){
            if(currNode.key === key){
                // key found, return corresponding value
                return currNode.value;
            }
            // move to next LL's node
            currNode = currNode.next;
        }
        // if key not found return null
        return undefined;
    }

    // utility method to rehash the HashMap if it exceed its load factor
    rehash(factor = 2){
        // double the capacity of the array 'arr'
        this.maxSize *= factor;

        // new array with updated capacity
        const newArr = Array(this.maxSize);

        for(let i = 0; i < this.maxSize; i++){
            newArr[i] = new MyLinkedList();
        }

        const oldArr = this.arr;

        // iterate on each node of every LL from oldArr and insert them into new array 'newArr'
        for(let i = 0; i < oldArr.length; i++){
            // go to each bucket of old array, each bucket has linked list
            let temp = oldArr[i].head;
            // console.log(temp);

            while(temp !== null){
                let key = temp.key;
                let value = temp.value;

                // find bucket index for new array
                const bucketIndex = this.hashFunction(key);

                // add key-value pair into new array 'newArr'
                newArr[bucketIndex].addAtHead(key,value);

                // update next pointer while iterating
                temp = temp.next;
            }
        }
        // make this new array as out hashmap array
        this.arr = newArr;
    }
}

const hm = new HashMap();
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

console.log(hm.search("Orange"));

hm.remove("chiku");
hm.display();

hm.update("mango", 49);
hm.display();