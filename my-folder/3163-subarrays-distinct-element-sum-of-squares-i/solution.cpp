class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> seen;
            for (int j = i; j < n; j++) {
                if (seen.find(nums[j]) == seen.end()) {
                    seen.insert(nums[j]);
                    if (j == i)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = dp[i][j - 1] + 1;
                }
                else {
                    dp[i][j] = dp[i][j - 1];
                }

                ans += dp[i][j] * dp[i][j];
            }
        }

        return ans;
    }
};
