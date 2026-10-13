class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        int half = n / 2;

        nth_element(nums.begin(), nums.begin() + half, nums.end(),
            [](int a, int b) {
                return abs(a) < abs(b);
            });

        long long ans = 0;
        int i=half-1;
        for(int j = n-1 ; j>=half ; j--){
            ans += 1LL*nums[j]*nums[j];
            if(i>=0){
                ans -= 1LL*nums[i]*nums[i];
                i--;
            }
        }

        return ans;
    }
};
