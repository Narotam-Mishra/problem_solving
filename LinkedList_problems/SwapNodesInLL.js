
// Problem link - https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

// ListNode class definition
function ListNode(val){
    this.val = val;
    this.next = null;
}

// utility function to create a linked list
function createLinkedList(arr){
    if(arr.length === 0) return null;
    let head = new ListNode(arr[0]);
    let cur = head;
    for(let i=1; i<arr.length; i++){
        cur.next = new ListNode(arr[i]);
        cur = cur.next;
    }
    return head;
}

// utility function to print linked list
function printLinkedList(head){
    let res = [];
    let cur = head;
    while(cur !== null){
        res.push(cur.val);
        cur = cur.next;
    }
    console.log(res.join(' -> '));
}

let swapNodes = function(head, k) {
    let i = 0;
    let fast = head;
    while(i < k-1 && fast !== null){
        i++;
        fast = fast.next;
    }
    let fNode = fast;
    // edge case
    if(fast === null){
        // remove head
        let newHead = head.next;
        head.next = null;
        return newHead;
    }

    let slow = head;
    while(fast.next !== null){
        // iterate till the fast doesn't reach the tail node
        slow = slow.next;
        fast = fast.next;
    }
    let sNode = slow;
    
    // logic to swap
    let temp = fNode.val;
    fNode.val = sNode.val;
    sNode.val = temp;

    return head;
};

// utility function to run the swapNodes function
function runSwapNodes(arr,k){
    // create linked list
    let head = createLinkedList(arr);

    // print original linked list
    console.log("Original linked list:");
    printLinkedList(head);

    // call swapNodes() to swap nodes values
    head = swapNodes(head, k);

    // print modified linked list:
    console.log("After swapping nodes:");
    printLinkedList(head);
}

let arr = [1,2,3,4,5];
let k = 2;
runSwapNodes(arr,k);