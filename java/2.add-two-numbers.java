/*
 * @lc app=leetcode id=2 lang=java
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        // dummy list is to return (head of the list)
        ListNode dummy = new ListNode(0); // creating an dummy list
        ListNode curr = dummy; // initializing an pointer
        int carry = 0;
        // need carry == 1 to avoid last sum to over 10
        while(l1 != null || l2 != null || carry == 1){
            int sum = 0; // initializing our sum
            // l1 and l2 value
            if(l1 != null){ // adding l1 to our sum & moving l1
                sum += l1.val;
                l1 = l1.next;
            }
            if(l2 != null){ // adding l2 to our sum & moving l2
                sum += l2.val;
                l2 = l2.next;
            }
            // carry bit
            sum += carry; 
            // get the 10th bit
            carry = sum/10; 
            // get the 1th bit
            ListNode node = new ListNode(sum % 10);
            curr.next = node; 
            curr = curr.next;
        }
        return dummy.next; // the first bit value doesn't matter
    }
}
// @lc code=end

