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
var removeNodes = function(head) {
    let st = [];
    while(head != null) {
        while(st.length > 0 && st[st.length - 1].val < head.val) {
            st.pop();
        }
        st.push(head);
        head = head.next;
    }
    
    let prev = null;
    while(st.length > 0) {
        let curr = st[st.length - 1];
        st.pop();
        curr.next = prev;
        prev = curr;
    }
    
    return prev;
};