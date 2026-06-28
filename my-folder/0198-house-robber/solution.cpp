class Solution {
public:
    int memo_rob(int i , vector<int>& mem , vector<int>& nums ){
        if(i < 0){
            return 0;
        }
        else if(mem[i] != -1){
            return  mem[i];
        }

        int take = nums[i] + memo_rob(i-2, mem, nums);
        int skip = memo_rob(i-1, mem, nums);
        mem[i] = max(take , skip);
        return mem[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> mem(n , -1);
        return memo_rob(n-1, mem , nums );
    }
};
