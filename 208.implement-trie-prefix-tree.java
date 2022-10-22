/*
 * @lc app=leetcode id=208 lang=java
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
class TrieNode {
    // String if we need to return the string
    boolean isEndOfWord;
    TrieNode[] children;
    public TrieNode() {
        this.isEndOfWord = false;
        // can use map?
        // key as character, value as the try data structure
        // https://www.youtube.com/watch?v=9PmMotHrkfY
        // Map children = new HashMap<char, TrieNode>();
        this.children = new TrieNode[26];
    }
}

public class Trie {
    private TrieNode root;
    public Trie() {
        root = new TrieNode();
    }

    // insert a word to the tree
    public void insert(String word) {
        // get the root
        TrieNode runner = root;
        // loop over the word
        for(char c : word.toCharArray()){
            // if runner->children[w - a] == null
            // get the id by c - 'a' since we store 26 char
            if(runner.children[c - 'a'] == null) {
                runner.children[c - 'a'] = new TrieNode();
            }
            runner = runner.children[c - 'a'];
        }
        runner.isEndOfWord = true;
    }

    // Returns if the word is in the trie.
    public boolean search(String word) {
        TrieNode runner = root;
        for(char c : word.toCharArray()) {
            if(runner.children[c - 'a'] == null) {
                return false;
            } else {
                runner = runner.children[c - 'a'];
            }
        }
        return runner.isEndOfWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    public boolean startsWith(String prefix) {
        TrieNode runner = root;
        for(char c : prefix.toCharArray()) {
            if(runner.children[c - 'a'] == null) {
                return false;
            } else {
                runner = runner.children[c - 'a'];
            }
        }
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
// @lc code=end

