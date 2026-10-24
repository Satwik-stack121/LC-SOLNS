class Solution {
public:
    vector<string> ans;
    int n;
    void solve(string s , int index , vector<string>& parts) {
        if(parts.size() == 4){
            if(index == n){
                ans.push_back( parts[0] + "." + parts[1] + "." + parts[2] + "." + parts[3] );
            }
        }

        for(int i = 1 ; i <= 3 ; i++){
            if(index+i > n){
                break;
            }

            string x = s.substr(index , i);
            if(x.size() > 1 && x[0] == '0'){
                continue;
            }

            if(stoi(x) > 255){
                continue;
            }

            parts.push_back(x);
            solve(s , index+i , parts );
            parts.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> parts;
        n=s.size();
        solve(s , 0 , parts );

        return ans;
        
    }
};
