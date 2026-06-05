class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(const string& tok : tokens){
            if(tok == "+" || tok == "-" || tok == "*" || tok == "/"){
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();

                int res;
                if(tok == "+") res = a + b;
                if(tok == "-") res = a - b;
                if(tok == "*") res = a * b;
                if(tok == "/") res = a / b;

                st.push(res);
            }
            else
                st.push(std::stoi(tok));
        }
        return st.top();
    }
};
