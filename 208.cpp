class Trie {
    bool isend;
    Trie* tab[26];
public:
    Trie() {
        isend = 0;
        memset(tab, 0, sizeof(tab));
    }
    
    void insert(string word) {
        Trie* node = this;
        for(char ch : word){
            int idx = ch - 'a';
            if(!node->tab[idx]){
                node->tab[idx] = new Trie();
            }
            node = node->tab[idx];
        }
        node->isend = 1;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(char ch : word){
            int idx = ch - 'a';
            if(!node->tab[idx]) return 0;
            node = node->tab[idx];
        }
        if(!node->isend) return 0;
        return 1;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(char ch : prefix){
            int idx = ch - 'a';
            if(!node->tab[idx]) return 0;
            node = node->tab[idx];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */