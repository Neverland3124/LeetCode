/*
 * @lc app=leetcode id=133 lang=java
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    public void dfs(Node node , Node copy , Node[] visited){
        visited[copy.val] = copy;
        // visited[3] = Node3
        for(Node n : node.neighbors){
            // not visited
            if(visited[n.val] == null){
                Node newNode = new Node(n.val);
                // copy is the old copy node
                copy.neighbors.add(newNode);
                dfs(n , newNode , visited);
            }else{
                // node exist, add n to copy's neighbor
                copy.neighbors.add(visited[n.val]);
            }
        }
        
    }
    public Node cloneGraph(Node node) {
        if(node == null) return null; 
        Node copy = new Node(node.val); 
        Node[] visited = new Node[101]; 
        Arrays.fill(visited , null);
        dfs(node , copy , visited); 
        return copy;
    }
}
// @lc code=end

