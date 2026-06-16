class Solution {
public:
    struct TrieNode{
        TrieNode* children[26];
        bool isTerminal;
    };

    TrieNode* root;
    vector<string> ans;

    void insert(vector<string>& words){
        for(string word : words){
            TrieNode* curr = root;
            for(char ch : word){
                int index = ch - 'a';
                if(curr-> children[index] == NULL){
                    curr->children[index] = new TrieNode();
                }

                curr = curr ->children[index];
            }
            curr -> isTerminal = true;
        }
    }

    void backtrack(int i, int j,vector<vector<char>>& board,TrieNode* node , string& currWord){

        
        if (i<0 || i>=board.size() || j<0 || j>=board[0].size()){
            return;
        }
        char currchar= board[i][j];
        if(currchar =='.'){
            return;
        }
        
        node = node ->children[currchar -'a'];
        if(!node){
            return;
        }
        currWord.push_back(currchar);
        
        if(node->isTerminal){
            ans.push_back(currWord);
            node->isTerminal = false;

        }
        board[i][j]= '.';
        backtrack(i+1, j, board, node, currWord);
        backtrack(i-1, j, board, node, currWord);
        backtrack(i, j+1, board, node, currWord);
        backtrack(i, j-1, board, node, currWord);

        board[i][j]=currchar;
        currWord.pop_back();
    }
        
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root= new TrieNode();
        insert(words);

        string currWord;

        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {
                backtrack(i, j, board, root, currWord);
            }
        }

        return ans;
    }
};
