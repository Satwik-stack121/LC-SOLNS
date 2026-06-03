class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int smallest=INT_MAX;

        int maxProfit=0;
        int n=0;
        while(n < prices.size()){
            if(prices[n]<smallest){
                smallest=prices[n];
            }
            else if(prices[n]-smallest>maxProfit){
                maxProfit=prices[n]-smallest;
            }
            n++;
        }
        return maxProfit;
    }
};
