class Solution {
public:
    bool isPalindrome(string s) {
        string s2;
        for(const char& i: s){
            if(isalnum(i)){
                s2.push_back(tolower(i));
            }
        }
        std::cout << s2 << std::endl;
        int lptr=0;
        int rptr=s2.size()-1;

        while(lptr <= rptr){
            if(s2[lptr] != s2[rptr]){
                return false;
            }
            lptr++;
            rptr--;
        }

        return true;
    }
};
