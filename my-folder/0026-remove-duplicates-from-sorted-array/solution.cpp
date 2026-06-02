class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lptr=1;
        int rptr=1;
        while(rptr < nums.size()) {
            if(nums[rptr] != nums[rptr-1]) {
                nums[lptr] = nums[rptr];
                lptr++;
            }
            rptr++;
        }
        return lptr;
    }
};
