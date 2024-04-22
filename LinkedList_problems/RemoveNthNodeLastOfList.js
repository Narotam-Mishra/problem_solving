
// Problem link - https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

function ListNode(val){
    this.val = val;
    this.next = null;
}

function getLinkedListLength(head){
    let length = 0;
    let cur = head;
    while(cur !== null){
        length++;
        cur = cur.next;
    }
    return length;
}

// Approach - 1 (using two pass)
let removeNthFromEnd1 = function(head, n) {
    let len = getLinkedListLength(head);
    let nthNodeIdx = len - n;
    if(nthNodeIdx === 0){
        return head.next;
    }

    let i = 0;
    let prev = null;
    let nodeToBeDel = head;
    while(i < nthNodeIdx && nodeToBeDel != null){
        prev = nodeToBeDel;
        nodeToBeDel = nodeToBeDel.next;
        i++;
    }
    // if nth node doesn't exist
    if(i !== nthNodeIdx){
        return head;
    }
    // update node refernce to remove
    prev.next = nodeToBeDel.next;
    return head;
};

// Approach - 2 (using single pass)
let removeNthFromEnd = function(head, n) {
    let i = 0;
    let fast = head;
    while(i<n && fast !== null){
        i++;
        fast = fast.next;
    }
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
    let nodeToBeDel = slow.next;
    slow.next = nodeToBeDel.next;
    nodeToBeDel.next = null;
    return head;
};

function printLinkedList(head){
    let res = [];
    let cur = head;
    while(cur !== null){
        res.push(cur.val);
        cur = cur.next;
    }
    console.log(res.join(' -> '));
}

// Create a sample linked list
let head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
head.next.next.next = new ListNode(4);
head.next.next.next.next = new ListNode(5);

console.log("Original:");
printLinkedList(head);

removeNthFromEnd(head,2);
console.log("After removing 2nd node from the end:");
printLinkedList(head);