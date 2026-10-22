class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return 0;
        }
        bool increasing = true;
        bool decreasing = true;

        for(int i =0 ; i<n ; i++){
            int next = (i+1)%n;
            if((nums[next] - nums[i] + n ) %n !=1){
                increasing = false;
            }
            if((nums[i] - nums[next] + n ) %n !=1){
                decreasing = false;
            }
        }
        if(!increasing && !decreasing){
            return -1;
        }
        int pos = find(nums.begin() , nums.end() , 0) - nums.begin();

        if(increasing){
            return min(pos , n-pos+2);
        }
        int posMax = find(nums.begin(), nums.end(), n - 1) - nums.begin();
        return min(posMax + 1, n + 1 - posMax);

    }
};
