class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       vector<int> str( 128,0 );

       if(s.empty()){
        return 0;
       }
       int left=0;
       int right=0;

       int maxlen=0;
       for(right; right< s.size() ; right++){
            while(str[s[right]]){
                str[s[left]]--;
                left++;
            }
            str[s[right]]= 1;

            maxlen= max(maxlen, right-left+1);
       } 
       return maxlen;
    }
    
};
