/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode[]}
 */
var splitListToParts = function(head, k) {
    let length = 0;
    let curr = head;
    
    while (curr !== null) {
        length++;
        curr = curr.next;
    }
 
    const partSize = Math.floor(length / k);
    let extraParts = length % k;
    
    const result = [];
    curr = head;
    
    for (let i = 0; i < k; i++) {
        let size = partSize + (extraParts > 0 ? 1 : 0);
        if (size > 0) {
            result.push(curr);
        } else {
            result.push(null);
        }

        for (let j = 1; j < size; j++) {
            if (curr !== null) {
                curr = curr.next;
            }
        }
        
        if (curr !== null) {
            let nextPart = curr.next;
            curr.next = null;
            curr = nextPart;
        }
        
        if (extraParts > 0) {
            extraParts--;
        }
    }
    
    return result;
};