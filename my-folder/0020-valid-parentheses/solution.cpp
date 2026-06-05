class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        vector<char> open ={'(', '[' , '{'};
        vector<char> close={')', ']', '}'};

        for(char c : s){
            
            if(count(close.begin(), close.end(), c)){

                int index = find(close.begin(), close.end(), c) - close.begin();

                if (stk.empty() || stk.top() != open[index]){
                    return false;
                }
                stk.pop();
            }
            else{
                stk.push(c);
            }

        }
        return stk.empty();
    }
};
