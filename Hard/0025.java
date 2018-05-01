/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode cur = head;
    	ListNode last = null;
    	int cnt = 0;
    	ListNode finder = cur;
    	boolean canSwap = true;
    	while(true){
        	for(int i=0;i<k;i++){
        		if(finder == null){
        			canSwap = false;
        			break;
        		}
        		finder = finder.next;
        	}
        	if(canSwap){
        		cnt++;
        		ListNode arr[] = new ListNode[k];
        		for(int i=0;i<k;i++){
        			arr[i] = cur;
        			cur = cur.next;
        		}
        		if(last!=null) last.next = arr[k-1];
        		for(int i=k-1;i>0;i--){
        			arr[i].next = arr[i-1];
        		}
        		arr[0].next = cur;
        		last = arr[0];
        		if(cnt == 1) head = arr[k-1];
        		finder = cur;
        	}else break;
    	}
        return head;
    }
}
