class Solution {
public:
    string maxSumOfSquares(int num, int sum) {

        int remainder = sum;
        if(sum > num*9){
            return "";
        }
        string answer(num, '0');

        for(int i=0 ; i < num ; i++){
            int cnum = min(9 , remainder);
            remainder -=cnum;
            answer[i] = '0' + cnum;
        }
        return answer;
    }
};
