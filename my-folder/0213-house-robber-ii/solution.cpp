class Solution {
public:
    int memo_rob(int i , int stop ,vector<int>& mem , vector<int>& nums ){
        if(i < stop){
            return 0;
        }
        else if(mem[i] != -1){
            return  mem[i];
        }

        int take = nums[i] + memo_rob(i-2, stop , mem, nums);
        int skip = memo_rob(i-1, stop , mem, nums);
        mem[i] = max(take , skip);
        return mem[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }

        vector<int> mem(n , -1);
        int ans1 = memo_rob(n-1, 1 , mem , nums);
        vector<int> mem2(n , -1);
        int ans2 = memo_rob(n-2 , 0 , mem2 , nums);
        return max(ans1 ,ans2);
    }
};
