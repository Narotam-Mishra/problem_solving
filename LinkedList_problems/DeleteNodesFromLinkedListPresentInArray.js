
// Problem link - https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/?envType=daily-question&envId=2025-11-01

// define singly-linked list
class ListNode {
    constructor(val = 0, next = null) {
        this.val = val;
        this.next = next;
    }
}

let modifiedList = function(nums, head) {
    const set = new Set(nums);
    
    // Step 1 - handle head deletion
    while (head !== null && set.has(head.val)) {
        head = head.next;
    }
    
    // Step 2 - handle deletion of intermediate nodes
    if (head === null) return null;
    
    let curr = head;
    while (curr !== null && curr.next !== null) {
        if (set.has(curr.next.val)) {
            curr.next = curr.next.next;
        } else {
            curr = curr.next;
        }
    }
    
    return head;
};

// helper function to create a linked list from array
function createList(values) {
    if (values.length === 0) return null;
    
    const head = new ListNode(values[0]);
    let curr = head;
    
    for (let i = 1; i < values.length; i++) {
        curr.next = new ListNode(values[i]);
        curr = curr.next;
    }
    
    return head;
}

// helper function to print linked list
function printList(head) {
    const values = [];
    let curr = head;
    while (curr !== null) {
        values.push(curr.val);
        curr = curr.next;
    }
    console.log(values.join(" -> "));
}

function main(){
    // // Test case 1
    // console.log("Test Case 1:");
    // const nums1 = [1, 2, 3];
    // const listValues1 = [1, 2, 3, 4, 5];

    // // Test case 2
    // console.log("Test Case 2:");
    // const nums1 = [1];
    // const listValues1 = [1, 2, 1, 2, 1, 2];

    // Test case 3
    console.log("Test Case 3:");
    const nums1 = [5];
    const listValues1 = [1, 2, 3, 4];
    let head1 = createList(listValues1);
    process.stdout.write("Original list: ");
    printList(head1);
    head1 = modifiedList(nums1, head1);
    process.stdout.write("Modified list: ");
    printList(head1);
}

main();