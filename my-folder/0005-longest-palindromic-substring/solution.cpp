class Solution {
public:
    bool memo_palindrome(int start, int end , string& s , vector<vector<int>>& memory){
        if(start >= end ){
            return true;
        }
        if(memory[start][end] != -1){
            return memory[start][end];
        }
        if(s[start] == s[end] && memo_palindrome(start + 1 , end - 1 , s , memory)){
            memory[start][end] = 1;
            return true;
        }
        memory[start][end] = 0;
        return false;
        
    }
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> memory(n ,vector<int>(n,-1));

        int start=0;
        int maxlen=1;

        for(int i=0; i<n ; i++){
            for(int j=i; j<n ; j++){
                if(memo_palindrome(i, j, s, memory) && j-i+1>maxlen){
                    start=i;
                    maxlen=j-i+1;
                }
            }
        }
        return s.substr(start, maxlen);
    }
};
