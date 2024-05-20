
// Problem link - https://leetcode.com/problems/partition-list/

// create Linked List Node

class ListNode{
    constructor(val){
        this.val = val;
        this.next = null;
    }
}

// utility method to create linked list
function createLinkedList(arr){
    if(!arr.length) return null;
    let head = new ListNode(arr[0]);
    let cur = head;
    for(let i=1; i<arr.length; i++){
        cur.next = new ListNode(arr[i]);
        cur = cur.next;
    }
    return head;
}

// utility method to print linked list
function printLinkedList(head){
    let cur = head;
    let res = "";
    while(cur){
        res += cur.val + " -> ";
        cur = cur.next;
    }
    res += "X";
    console.log(res);
}

let partition = function(head, x) {
    // in order to two create partitions, we will use two list nodes
    let l1 = new ListNode(-1);
    let l2 = new ListNode(-1);

    // create two nodes to maintain tail of the node
    let t1 = l1;
    let t2 = l2;

    // iterate through the list 
    // pertform partiton of the list
    let cur = head;
    while(cur != null){
        let temp = cur;
        cur = cur.next;
        // isolate the node
        temp.next = null

        // all values which are less than x should be in left of x
        if(temp.val < x){
            t1.next = temp;
            t1 = t1.next;
        }else{
            t2.next = temp;
            t2 = t2.next;
        }
    }

    // attach two partition lists
    t1.next = l2.next;
    l2.next = null;

    // before returing attached list
    // detach l1 because list l1 is not needed any more
    let res = l1.next;
    l1.next = null;

    // return the single list
    return res;
};

let arr = [1,4,3,2,5,2];
let x = 3;

let head = createLinkedList(arr);
console.log("Oriignal Linked List:");
printLinkedList(head);
let partitonedHead = partition(head, x);
console.log("Partitioned Linked List:");
printLinkedList(partitonedHead);