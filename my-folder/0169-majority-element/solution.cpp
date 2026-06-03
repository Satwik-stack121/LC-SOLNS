class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int numHand = nums[0];
        int numCount = 0;
        for (int num : nums){

            if (num == numHand){
                numCount++;
            }
            else{
                numCount--;
            } 
            if (numCount == -1){
                numHand = num;
                numCount = 1;
            }
        } 
        return numHand;
    }
};
