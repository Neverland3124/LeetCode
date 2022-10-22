/*
 * @lc app=leetcode id=706 lang=java
 *
 * [706] Design HashMap
 */

// @lc code=start
// easy way: use array, not fast
// class MyHashMap {
//     int[] data;
//     public MyHashMap() {
//         data = new int[1000001];
//         Arrays.fill(data, -1);
//     }
//     public void put(int key, int val) {
//         data[key] = val;
//     }
//     public int get(int key) {
//         return data[key];
//     }
//     public void remove(int key) {
//         data[key] = -1;
//     }
// }


// hash way, linked list, faster
class ListNode {
    int key, val;
    ListNode next;
    public ListNode(int key, int val, ListNode next) {
        this.key = key;
        this.val = val;
        this.next = next;
    }
}
class MyHashMap {
    static final int size = 19997;
    static final int mult = 12582917;
    ListNode[] data;
    public MyHashMap() {
        this.data = new ListNode[size];
    }
    // hash function
    private int hash(int key) {
        return (int)((long)key * mult % size);
    }
    // put
    public void put(int key, int val) {
        // if exist, remove it (since we need to update the key)
        remove(key);
        // find h
        int h = hash(key);
        // initialize the node
        ListNode node = new ListNode(key, val, data[h]);
        // store in the head
        data[h] = node;
    }
    // get
    public int get(int key) {
        // find h
        int h = hash(key);
        // find the first node of h
        ListNode node = data[h];
        // search the key and return the value
        for (; node != null; node = node.next)
            if (node.key == key) return node.val;
        return -1;
    }
    // remove to set null
    public void remove(int key) {
        // find node of h
        int h = hash(key);
        ListNode node = data[h];
        // not exist
        if (node == null) return;
        // the first one, set to next one
        if (node.key == key) data[h] = node.next;
        else for (; node.next != null; node = node.next)
            // skip this one so that we cannot find it
            if (node.next.key == key) {
                node.next = node.next.next;
                return;
            }
    }
}


/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */
// @lc code=end

