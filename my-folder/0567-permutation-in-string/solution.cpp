class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1s = s1.size();
        int s2s = s2.size();
        
        if( s1s > s2s){
            return false;
        }
        vector<int> freq1(26 , 0);
        vector<int> freq2(26 , 0);
        
        for(int i = 0; i < s1s; i++){
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        int left = 0;
        if(freq1 == freq2){
            return true;
        }

        for(int right= s1s ; right<s2s; right++){
            freq2[s2[right] - 'a']++;
            freq2[s2[left] - 'a']--;
            left++;
            if(freq1 == freq2){
                return true;
            }
        }
        return false;
    }
};
