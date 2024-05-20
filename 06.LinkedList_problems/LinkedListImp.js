
// Implement Linked List

function createNode(value){
    return{
        data: value,
        next: null
    }
}

function displayLinkedList(head){
    let temp = head;
    let res = "";
    while(temp != null){
        res = res + temp.data + " -> ";
        temp = temp.next;
    }
    res += "X";
    console.log(res);
}

function addAtHead(head, data){
    // created linked list node
    let newNode = createNode(data);
    // this step attaches the new node to the head of the list
    newNode.next = head;
    // this step updates the head of the list
    head = newNode
    return head;
}

function addAtTail(head, data){
    if(head == null){
        // when LL is empty
        return addAtHead(head, data);
    }
    // traverse the LL till reach tail node
    let temp = head;
    while(temp.next != null){
        temp = temp.next;
    }
    // now temp has access to the tail node
    let newNode = createNode(data);
    temp.next = newNode;

    return head;
}

function addAtIndex(head, i, data){
    if(head == null){
        return addAtHead(head);
    }
    let temp = head;
    let count = 0;
    while(count < i-1){
        temp = temp.next;
        count += 1;
    }
    // temp points to i-1th node
    prevI = temp.next;

    let newNode = createNode(data);
    temp.next = newNode;
    newNode.next = prevI;
    return head;
}

function removeFromHead(head){
    if(head == null){
        // LL is empty
        return null;
    }
    // store the access of the new head to be made
    let newHead = head.next;
    // remove the linking of the old head
    head.next = null;
    return newHead;
}

function removeAtTail(head){
    if(head == null){
        // LL is empty
        return null;
    }

    if(head.next == null){
        // LL contain single node
        return null;
    }
    let cur = head;
    while(cur.next.next != null){
        cur = cur.next;
    }

    // now cur has access to 2nd last node
    temp.next = null;
    return head;
}

function removeAtIndex(head, i){
    if(head === null){
        // LL is empty
        return head;
    }

    if(head.next === null){
        return null;
    }

    let temp = head;
    let count = 0;
    while(temp.next != null && count < i-1){
        temp = temp.next;
        count += 1;
    }

    // if ith index is greater than length of LL
    if(temp.next === null && count <= i-1){
        return head;
    }

    // temp points at i-1th node
    let nodeToBeDel = temp.next;
    let nextToBeDel = temp.next.next;
    temp.next = nextToBeDel;
    nodeToBeDel.next = null;
    return head;
}

// * Time: O(N)
// * Space: O(1)
function midOfLinkedList(head){
    if(head === null){
        return head;
    }
    let slow = head;
    let fast = head;
    while(fast.next !== null && fast.next.next !== null){
        slow = slow.next;
        fast = fast.next.next;
    }
    if(fast.next === null) return slow;
    else return slow.next;
};

let head = null;

head = addAtHead(head, 10); // 10->
head = addAtHead(head, 20); // 20->10->x
head = addAtHead(head, 30); // 30->20->10->x
head = addAtHead(head, 40); // 40->30->20->10->x
head = addAtHead(head, 50); // 50->40->30->20->10->x
head = addAtTail(head, 100); // 50->40->30->20->10->100->x
head = addAtTail(head, 90);  // 50->40->30->20->10->100->90->x

displayLinkedList(head);

head = removeAtIndex(head, 4);
displayLinkedList(head);

let mid = midOfLinkedList(head);
console.log("Mid Element:", mid.data);