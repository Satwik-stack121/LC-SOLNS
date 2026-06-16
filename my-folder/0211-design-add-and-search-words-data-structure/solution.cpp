class WordDictionary {
public:
    struct TrieNode{
        bool isterminal;
        TrieNode* children[26];
    };

    TrieNode* root;

    bool search2(string& word, int pos, TrieNode* curr) {
        if(pos==word.size()){
            return curr->isterminal;
        }
        char ch=word[pos];

        if(ch =='.'){
            for(int i = 0; i < 26; i++){
                if(curr->children[i]){
                    if(search2(word, pos+1,curr->children[i])){
                        return true;
                    }
                }
            }
            return false;
        }
        int index= ch-'a';

        if (!curr->children[index]) {
            return false;
        }
        return search2(word, pos+1,curr->children[index]);
    }

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char ch : word){
            int index = ch - 'a';
            if(curr-> children[index] == NULL){
                curr->children[index] = new TrieNode();
            }

            curr = curr ->children[index];
        }
        curr -> isterminal = true;        
    }
    
    bool search(string word) {
        return search2(word ,0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
