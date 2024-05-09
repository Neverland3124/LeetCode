/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode* next;
    // below is the constructors
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // given l1 = = [2,4,3], l2 = [5,6,4]
        // need to return [7,0,8]

        // some setups
        // p, q, curr are pointers
        // cur point to a linkedlist of 0
        ListNode* dummyHead = new ListNode(0);
        ListNode *p = l1, *q = l2, *curr = dummyHead;
        int carry = 0;

        // core loop
        // while p or q is not null
        while (p != nullptr || q != nullptr) {
            // set x and y's value, if they are null set to 0
            int x = (p != nullptr) ? p->val : 0;
            int y = (q != nullptr) ? q->val : 0;
            // sum is carry + x + y, to store in this node
            int sum = carry + x + y;
            // if sum is 11, carry is 1
            carry = sum / 10;
            // next node is the number digit
            // store the digit and move the pointer to next node
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            // moe p and q's pointer
            if (p != nullptr) p = p->next;
            if (q != nullptr) q = q->next;
        }
        // if after while loop we still have curry, then add a new node or carry
        // to the end represent 1 in the first digit
        if (carry > 0) {
            curr->next = new ListNode(carry);
        }

        // return the linkedlist
        return dummyHead->next;
    }
};
// @lc code=end
