class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int l_ptr = 0;
        int r_ptr = 0;
        int max_sum=nums[0];
        int curr_sum = 0;
        int n=nums.size();
        for(int i = 0 ; i< n ; i++){
            if(curr_sum < 0){
                curr_sum = 0;
                // curr_sum += nums[i];
            }
            curr_sum += nums[i];
            max_sum = max(curr_sum , max_sum);
            
        }
        return max_sum;
    }
};
