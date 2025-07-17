class TrieNode {
public:
    TrieNode* child[26];
    bool wordEnd;
    TrieNode() {
        wordEnd = false;
        for (int i = 0; i < 26; i++)
            child[i] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (curr->child[word[i] - 'a'] == nullptr)
                curr->child[word[i] - 'a'] = new TrieNode();
            curr = curr->child[word[i] - 'a'];
        }
        curr->wordEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (curr->child[word[i] - 'a'] == nullptr) return false;
            curr = curr->child[word[i] - 'a'];
        }
        return curr->wordEnd; 
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (curr->child[prefix[i] - 'a'] == nullptr) return false;
            curr = curr->child[prefix[i] - 'a'];
        }
        return true; 
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */