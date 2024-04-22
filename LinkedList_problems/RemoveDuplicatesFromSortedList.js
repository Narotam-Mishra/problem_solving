
// Problem link - https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

let deleteDuplicates = function(head) {
    let cur = head;
    while(cur !== null && cur.next !== null){
        if(cur.val === cur.next.val){
            let nodeToBeDel = cur.next;
            cur.next = nodeToBeDel.next;
            nodeToBeDel.next = null;
        }else{
            cur = cur.next;
        }
    }
    return head;
};