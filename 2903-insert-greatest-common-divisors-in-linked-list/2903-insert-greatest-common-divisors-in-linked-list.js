/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
function gcd(a, b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

var insertGreatestCommonDivisors = function(head) {
    let curr = head;
    
    while(curr.next != null) {
        const val = gcd(curr.val, curr.next.val);
        let temp = curr.next;
        let newNode = new ListNode(val);
        curr.next = newNode;
        newNode.next = temp;
        curr = temp;
    }

    return head;
};