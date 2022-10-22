// import java.util.PriorityQueue;

/*
 * @lc app=leetcode id=23 lang=java
 *
 * [23] Merge k Sorted Lists
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
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists==null || lists.length==0) return null;
        ListNode dummy = new ListNode(0);
        ListNode tail=dummy;
        
        PriorityQueue<ListNode> queue= new PriorityQueue<ListNode>(lists.length, (a,b)-> a.val-b.val);
        
        for (ListNode node:lists)
            if (node!=null)
                queue.add(node);
            
        while (!queue.isEmpty()){
            tail.next=queue.poll();
            tail=tail.next;
            
            // because that queue only have the start of all lists, it have to have 
            // the rest if the tail is used
            if (tail.next!=null)
                queue.add(tail.next);
        }
        return dummy.next;
    }
}

// class Solution {
//     public ListNode mergeKLists(ListNode[] lists) {
//         if(lists.length == 0){
//             return null;
//         }
//         return merge_range(lists, 0, lists.length - 1);
//     }
//     public ListNode merge_range(ListNode[] lists, int start, int end){
//         if(start == end){
//             return lists[start];
//         }
//         int m = (start + end) / 2;
//         ListNode node_1 = merge_range(lists, start, m);
//         ListNode node_2 = merge_range(lists, m+1, end);
//         return merge_two(node_1, node_2);
//     } 
//     public ListNode merge_two(ListNode node_1, ListNode node_2){
//         ListNode node_list = new ListNode();
//         ListNode head = node_list;
//         while(node_1 != null && node_2 != null){
//             if(node_1.val < node_2.val){
//                 ListNode new_node = new ListNode(node_1.val);
//                 node_list.next = new_node;
//                 node_list = node_list.next;
//                 node_1 = node_1.next;
//             }else{
//                 ListNode new_node = new ListNode(node_2.val);
//                 node_list.next = new_node;
//                 node_list = node_list.next;
//                 node_2 = node_2.next;
//             }
//         }
//         while(node_1 != null){
//             ListNode new_node = new ListNode(node_1.val);
//             node_list.next = new_node;
//             node_list = node_list.next;
//             node_1 = node_1.next;
//         }
//         while(node_2 != null){
//             ListNode new_node = new ListNode(node_2.val);
//             node_list.next = new_node;
//             node_list = node_list.next;
//             node_2 = node_2.next;
//         }
//         return head.next;
        
//     }
// }
// @lc code=end

