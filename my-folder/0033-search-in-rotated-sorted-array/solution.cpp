class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right= nums.size()-1;
        while(left< right){
            int mid= (left+right)/2;

            if(nums[mid] > nums[right]){
                left=mid+1;
            }

            else{
                right=mid;
            }
        }
        int min_idx = left;
        if (target >= nums[min_idx] && target <= nums[nums.size() - 1]){
            left = min_idx;
            right = nums.size()-1;
        } 
        else{
            left = 0;
            right=min_idx-1;
        }

        while(left<= right){
            int mid= (left+right)/2;

            if(nums[mid]== target){
                return mid;
            }
            else if(nums[mid] > target){
                right=mid-1;
            }

            else{
                left=mid+1;
            }
        }
        return -1;
    }
};
