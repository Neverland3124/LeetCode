/*
 * @lc app=leetcode id=146 lang=java
 *
 * [146] LRU Cache
 */

// @lc code=start
// least recent used cache
// cscc69 virtual memory evict system
class LRUCache {
    // store the list
    LinkedNodeList list;
    // map
    Map<Integer, Node> map;
    // capacity
    Integer cap;

    // constructor
    public LRUCache(int capacity) {
        // new
        list = new LinkedNodeList();
        // size
        map = new HashMap(capacity);
        cap = capacity;
    }

    // get the key
    public int get(int key) {
        // integer.node
        // from map get the node
        Node node = map.get(key);
        if (node == null) {
            return -1;
        }
        // move to head indicate used
        list.moveToHead(node);
        // return value
        return node.val;
    }

    // put
    public void put(int key, int value) {
        Node node = map.get(key);
        if (node != null) {
            // node is not null
            // update value
            list.moveToHead(node);
            node.val = value;
        } else {
            // node is null, new node
            Node newNode = new Node(key, value);
            // exceed size
            if (map.size() == cap) {
                // tail use to make sure O(1)
                Node tail = list.getTail();
                // remove it from the map
                map.remove(tail.key);
                // remove the least used one
                list.removeTail();
            }
            // put into the map
            map.put(key, newNode);
            // put to the head
            list.addToHead(newNode);
        }
    }
}

// double linked list
class LinkedNodeList {
    // dummy head and dummy tail is used to keep the head and tail
    // they are not real head or tail
    Node dummyHead;
    Node dummyTail;

    LinkedNodeList() {
        // head and tail list
        dummyHead = new Node(0, 0);
        dummyTail = new Node(0, 0);
        dummyHead.next = dummyTail;
        dummyTail.prev = dummyHead;
    }

    void moveToHead(Node node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
        addToHead(node);
    }

    void addToHead(Node node) {
        Node tmp = dummyHead.next;
        dummyHead.next = node;
        node.next = tmp;
        node.prev = dummyHead;
        tmp.prev = node;
    }

    // return tail
    void removeTail() {
        Node newTail = dummyTail.prev.prev;
        newTail.next = dummyTail;
        dummyTail.prev = newTail;
    }

    // get last.prev
    Node getTail() {
        return dummyTail.prev;
    }

}

class Node {
    // key - value
    int key;
    int val;
    // next - prev
    Node next;
    Node prev;

    Node(int key, int value) {
        this.key = key;
        this.val = value;
    }
}
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
// @lc code=end
