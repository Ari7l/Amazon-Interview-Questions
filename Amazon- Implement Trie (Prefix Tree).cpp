class TrieNode{
    public:
     bool isWord ;
     TrieNode* child[26];
     TrieNode(){
           isWord = false;
          for(int i=0;i<26;++i) child[i] = NULL;
     }
};

class Trie {
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    
    Trie() {
        root = new TrieNode();
    }
     ~Trie(){
         delete root;
     }
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *curr = root;
        int k = 0;
        for(char ch: word){
            k = ch - 'a';
            if(!curr->child[k]) curr->child[k] = new TrieNode();
            curr = curr->child[k];
        }
        curr->isWord = true;
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *curr = root;
        int k = 0;
        for(char ch: word){
            k = ch - 'a';
            if(!curr->child[k]) return false;
            curr = curr->child[k];
        }
       return curr->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
         TrieNode *curr = root;
         int k = 0;
        for(char ch: prefix){
            k = ch - 'a';
            if(!curr->child[k]) return false;
            curr = curr->child[k];
        }
       return true;
    }
};
