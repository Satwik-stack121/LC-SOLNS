class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt5=0;
        int cnt10=0;
        for(const auto &i : bills){
            if(i == 5){
                cnt5++;
            }
            else if(i==10){
                if(cnt5 < 1){
                    return false;
                }
                else{
                    cnt5--;
                    cnt10++;
                }    
            }
            else{
                if(cnt5 >=1 && cnt10 >=1){
                    cnt5--;
                    cnt10--;
                    continue;
                }
                else if(cnt5 >=3){
                    cnt5 = cnt5-3;
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
