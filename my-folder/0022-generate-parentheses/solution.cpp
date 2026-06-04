class Solution {
public:
    void backtrack(vector<string> & solution, string & current, int opcnt, int clcnt, int n){
        if(opcnt==clcnt && opcnt==n){
            solution.push_back(current);
        }

        if(opcnt<n){
            current.push_back('(');
            backtrack(solution, current, opcnt+1, clcnt, n);
            current.pop_back();
        }

        if(clcnt < opcnt){
            current.push_back(')');
            backtrack(solution, current, opcnt, clcnt+1, n);
            current.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> solution;
        string current;
        int opcnt = 0;
        int clcnt = 0;
        backtrack(solution, current, opcnt, clcnt, n);
        return solution;
    }
};
