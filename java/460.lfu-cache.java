/*
 * @lc app=leetcode id=460 lang=java
 *
 * [460] LFU Cache
 */

// @lc code=start
import java.util.*;

public class LFUCache {
    // node structure
    class Node {
        // count = cnt is set to 1 at first
        int key, val, cnt;
        Node prev, next;

        Node(int key, int val) {
            this.key = key;
            this.val = val;
            cnt = 1;
        }
    }

    // double linked list
    // no field of count since we use hashmap to store it
    class DLList {
        // head & tail
        Node head, tail;
        int size;

        // init
        DLList() {
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head.next = tail;
            tail.prev = head;
        }

        // add to the list and resize
        void add(Node node) {
            head.next.prev = node;
            node.next = head.next;
            node.prev = head;
            head.next = node;
            size++;
        }

        // remove and resize
        void remove(Node node) {
            node.prev.next = node.next;
            node.next.prev = node.prev;
            size--;
        }

        // remove last elem in the node, if size == 0, return null
        Node removeLast() {
            if (size > 0) {
                Node node = tail.prev;
                remove(node);
                return node;
            } else
                return null;
        }
    }

    // c, s, min
    int capacity, size, min;

    // mode map of all nodes
    // have all the nodes
    Map<Integer, Node> nodeMap;
    // todo: why this count map?
    // count map, value is double linked list
    Map<Integer, DLList> countMap;

    // constructor
    public LFUCache(int capacity) {
        this.capacity = capacity;
        nodeMap = new HashMap<>();
        countMap = new HashMap<>();
    }

    // get the key
    public int get(int key) {
        Node node = nodeMap.get(key);
        if (node == null)
            return -1;
        // cnt + 1
        update(node);
        return node.val;
    }

    // put a key to the list
    public void put(int key, int value) {
        // edge case
        if (capacity == 0)
            return;
        Node node;
        // if nodeMao have the key
        if (nodeMap.containsKey(key)) {
            // get it and update it (same as get + update)
            node = nodeMap.get(key);
            node.val = value;
            update(node);
        } else {
            // new key
            node = new Node(key, value);
            // put to the node map
            nodeMap.put(key, node);
            // evict if react max
            if (size == capacity) {
                // get the last one and remove it
                DLList lastList = countMap.get(min);
                nodeMap.remove(lastList.removeLast().key);
                size--;
            }
            // not full
            size++;
            // reset min to the the new node
            min = 1;
            DLList newList;
            if (countMap.get(node.cnt) != null) {
                newList = countMap.get(node.cnt);
            } else {
                newList = new DLList();
            }
            // same as
            // DLList newList = countMap.getOrDefault(node.cnt, new DLList());
            // add the new node to the DLList
            newList.add(node);
            // put the new list to the countMap
            countMap.put(node.cnt, newList);
        }
    }

    // if get/put the node, update the cnt
    private void update(Node node) {
        // get the node
        // use count to get the double list
        DLList oldList = countMap.get(node.cnt);
        // remove it from the list
        // from the list remove it
        oldList.remove(node);

        // if count is min and size = 0, min ++
        // since the min DLList is empty
        if (node.cnt == min && oldList.size == 0)
            min++; // since node will continue be min
        // count ++
        node.cnt++;
        // add to the newList
        DLList newList;
        if (countMap.get(node.cnt) != null) {
            newList = countMap.get(node.cnt);
        } else {
            newList = new DLList();
        }
        // same as
        // DLList newList = countMap.getOrDefault(node.cnt, new DLList());
        newList.add(node);
        countMap.put(node.cnt, newList);
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
// @lc code=end
