/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

#include <unordered_map>
#include <vector>
using namespace std;

class Node {
   public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
   public:
    Node* cloneGraph(Node* node) {
        // Question: We need to return a copy of the graph, cannot use the original graph
        // Idea: Loop over the nodes and create a copy, return the head of the copy
        // Issue: We don't know if we go over the same node again, so we need to use something to
        // store the visited nodes Solution: Use *** to store it

        if (node == NULL) return NULL;
        unordered_map<Node*, Node*> visited;
        return dfs(node, visited);
    }

    Node* dfs(Node* node, unordered_map<Node*, Node*>& visited) {
        if (visited.find(node) != visited.end()) return visited[node];

        Node* newNode = new Node(node->val);
        visited[node] = newNode;

        for (Node* neighbor : node->neighbors) {
            newNode->neighbors.push_back(dfs(neighbor, visited));
        }

        return newNode;
    }
};
// @lc code=end
