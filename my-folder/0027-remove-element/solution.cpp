
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int wptr=0;
        int rptr=0;

        while(rptr<nums.size()){

            if (nums[rptr] != val){
                nums[wptr] = nums[rptr];
                wptr++;
            }
            rptr++;
        
        
        }
        return wptr;
    }
};
