class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        vector<int> frequency(26,0);
        
        for(int i = 0; i < s.size() ; i++){
            frequency[s[i]-'a']+=1;
            frequency[t[i]-'a']-=1;
        }

        // for(int i = 0; i < s.size() ; i++){
        //     frequency[t[i]-'a']+=1;
        // }

        for(int i : frequency){
            if(i != 0){
                return false;
            }
        }

        return true;

    }
};
