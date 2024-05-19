/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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

#include <vector>
#include <queue>
using namespace std;

// struct ListNode {
//     int val;
//     ListNode* next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode* next) : val(x), next(next) {}
// };

class Solution {
   public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Note: The way for two list merge is not suitable for k list merge,
        // because the input size now is a variable, what we can do use to use a
        // heap to store all lists and then pop the smallest to a new list.
        // Idea: Use heap

        // This creates a min heap
        priority_queue<int, vector<int>, greater<int>> heap;

        // Push all elements to heap
        // TODO: review this for loop
        for(auto list : lists) {
            while(list) {
                heap.push(list->val);
                list = list->next;
            }
        }

        // Create a listNode
        ListNode* mergedList = new ListNode();
        ListNode* headNode = mergedList;

        // Pop all elements from heap and create a new list
        // TODO: review heap functions
        while(!heap.empty()) {
            headNode->next = new ListNode(heap.top());
            heap.pop();
            headNode = headNode->next;
        }

        return mergedList->next;
    }
};
// @lc code=end
