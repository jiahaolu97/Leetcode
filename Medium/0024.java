/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode cur = head;
        ListNode last = null;
        int cnt = 0;
        while(cur!=null && cur.next != null){
        	cnt++;
        	ListNode first = cur;
        	ListNode second = cur.next;
        	cur = second.next;
        	if(last!=null){
        		last.next = second;
        	}
        	first.next = cur;
        	second.next = first;
        	if(cnt == 1){
        		head = second;
//        		System.out.println("head"+head);
        	}
        	last = first;
        }
        return head;
    }
}
