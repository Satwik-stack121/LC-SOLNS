class Solution {
public:
    bool memo_palindrome(int start, int end , string& s , vector<vector<int>>& memory ){
        if (start >= end) {
            return true;
        }

        if (memory[start][end] != -1) {
            return memory[start][end];
        }

        if (s[start] == s[end] && memo_palindrome(start + 1, end - 1, s, memory)){
            memory[start][end] = 1;
        }
        else{
            memory[start][end] = 0;
        }
        return memory[start][end];
    }
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<int>> memory(n ,vector<int>(n,-1));
        int count=0;
        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                if (memo_palindrome(i, j, s, memory)){
                    count++;
                }
            }
        }

        return count;
    }
};
