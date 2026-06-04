class Solution {
public:
    void backtrack(vector<vector<char>>& board, bool& solution, string& word, string& current, int i, int j){
        if (current==word){
            solution = true;
            return;
        }
        if (i<0 || i>=board.size() || j<0 || j>=board[0].size()){
            return;
        }

        if (board[i][j]=='.' || board[i][j]!=word[current.length()]){
            return;
        }

        char temp = board[i][j];
        current.push_back(temp);
        board[i][j] = '.';

        if(!solution){
            backtrack(board, solution, word, current, i + 1, j);
        }
        if(!solution){
            backtrack(board, solution, word, current, i - 1, j);
        }
        if(!solution){
            backtrack(board, solution, word, current, i, j + 1);
        }
        if(!solution){
            backtrack(board, solution, word, current, i, j - 1);
        }

        board[i][j] = temp;
        current.pop_back();
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        bool solution = false;
        string current = "";
        for (int i=0; i<board.size(); i++){
            for (int j=0; j<board[0].size(); j++){
                backtrack(board, solution, word, current, i, j);
                if (solution) return true;
            }
        }
    return solution;
    }
};
