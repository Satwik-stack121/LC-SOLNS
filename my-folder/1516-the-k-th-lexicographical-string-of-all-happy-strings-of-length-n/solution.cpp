class Solution {
public:
    vector<string> letters = {"a" , "b" , "c"};
    vector<string> ans;

    void solve(int n, int k , vector<string> happy, string prev ){
        if(happy.size() == n){
            string temp = "";
            for(auto& i : happy){
                temp+=i;
            }
            ans.push_back(temp);
            return;
        }
        

        for(auto&i : letters){
            if(i == prev){
                continue;
            }
            happy.push_back(i);
            solve(n , k , happy , i);
            happy.pop_back();

        }
    }
    string getHappyString(int n, int k) {
        vector<string> happy;
        solve(n , k , happy , "");
        if(ans.size() >= k){
            return ans[k-1];
        }
        else{
            return "";
        }
    }
};
