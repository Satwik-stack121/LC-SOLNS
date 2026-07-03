class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for(int a = 0; a <= amount; a++){
            for(int coin : coins){
                if(coin <= a)
                    dp[a] = min(dp[a], 1 + dp[a - coin]);
            }
            // printf("%d ", dp[a]);
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
