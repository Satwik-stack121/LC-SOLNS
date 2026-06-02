class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string output="";
        int i = 0;
        while(i < strs[0].size()){

            char compare=strs[0][i];
            for(const string& str : strs){
                if(str[i] != compare){
                    return output;
                }
            }
            output=output+compare;
            i++;
                
        }
        return output;
        
    }
};
